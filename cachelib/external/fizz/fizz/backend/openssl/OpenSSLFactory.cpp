/*
 *  Copyright (c) 2018-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 */

#include <fizz/backend/openssl/OpenSSLFactory.h>
#include <fizz/backend/openssl/certificate/CertUtils.h>
#include <fizz/fizz-config.h>

#if FIZZ_HAVE_OQS
#include <fizz/crypto/exchange/HybridKeyExchange.h>
#include <fizz/experimental/crypto/exchange/OQSKeyExchange.h>
#endif

#if FIZZ_BUILD_AEGIS
#include <fizz/crypto/aead/AEGISCipher.h>
#endif

namespace fizz {
namespace openssl {

std::unique_ptr<KeyExchange> OpenSSLFactory::makeKeyExchange(
    NamedGroup group,
    KeyExchangeMode mode) const {
  (void)mode;
  switch (group) {
    case NamedGroup::secp256r1:
      return std::make_unique<OpenSSLECKeyExchange<P256>>();
    case NamedGroup::secp384r1:
      return std::make_unique<OpenSSLECKeyExchange<P384>>();
    case NamedGroup::secp521r1:
      return std::make_unique<OpenSSLECKeyExchange<P521>>();
    case NamedGroup::x25519:
      return std::make_unique<X25519KeyExchange>();
#if FIZZ_HAVE_OQS
    case NamedGroup::x25519_kyber512:
    case NamedGroup::x25519_kyber512_experimental:
      return std::make_unique<HybridKeyExchange>(
          std::make_unique<X25519KeyExchange>(),
          OQSKeyExchange::createOQSKeyExchange(mode, OQS_KEM_alg_kyber_512));
    case NamedGroup::secp256r1_kyber512:
      return std::make_unique<HybridKeyExchange>(
          std::make_unique<OpenSSLECKeyExchange<P256>>(),
          OQSKeyExchange::createOQSKeyExchange(mode, OQS_KEM_alg_kyber_512));
    case NamedGroup::kyber512:
      return OQSKeyExchange::createOQSKeyExchange(mode, OQS_KEM_alg_kyber_512);
    case NamedGroup::x25519_kyber768_draft00:
    case NamedGroup::x25519_kyber768_experimental:
      return std::make_unique<HybridKeyExchange>(
          std::make_unique<X25519KeyExchange>(),
          OQSKeyExchange::createOQSKeyExchange(mode, OQS_KEM_alg_kyber_768));
    case NamedGroup::secp256r1_kyber768_draft00:
      return std::make_unique<HybridKeyExchange>(
          std::make_unique<OpenSSLECKeyExchange<P256>>(),
          OQSKeyExchange::createOQSKeyExchange(mode, OQS_KEM_alg_kyber_768));
    case NamedGroup::secp384r1_kyber768:
      return std::make_unique<HybridKeyExchange>(
          std::make_unique<OpenSSLECKeyExchange<P384>>(),
          OQSKeyExchange::createOQSKeyExchange(mode, OQS_KEM_alg_kyber_768));
#endif
    default:
      throw std::runtime_error("ke: not implemented");
  }
}

std::unique_ptr<Aead> OpenSSLFactory::makeAead(CipherSuite cipher) const {
  switch (cipher) {
    case CipherSuite::TLS_CHACHA20_POLY1305_SHA256:
      return OpenSSLEVPCipher::makeCipher<ChaCha20Poly1305>();
    case CipherSuite::TLS_AES_128_GCM_SHA256:
      return OpenSSLEVPCipher::makeCipher<AESGCM128>();
    case CipherSuite::TLS_AES_256_GCM_SHA384:
      return OpenSSLEVPCipher::makeCipher<AESGCM256>();
    case CipherSuite::TLS_AES_128_OCB_SHA256_EXPERIMENTAL:
      return OpenSSLEVPCipher::makeCipher<AESOCB128>();
#if FIZZ_BUILD_AEGIS
    case CipherSuite::TLS_AEGIS_256_SHA512:
      return AEGIS::make256();
    case CipherSuite::TLS_AEGIS_128L_SHA256:
      return AEGIS::make128L();
#endif
    default:
      throw std::runtime_error("aead: not implemented");
  }
}

std::unique_ptr<KeyDerivation> OpenSSLFactory::makeKeyDeriver(
    CipherSuite cipher) const {
  switch (cipher) {
    case CipherSuite::TLS_CHACHA20_POLY1305_SHA256:
    case CipherSuite::TLS_AES_128_GCM_SHA256:
    case CipherSuite::TLS_AES_128_OCB_SHA256_EXPERIMENTAL:
    case CipherSuite::TLS_AEGIS_128L_SHA256:
      return KeyDerivationImpl::make<Sha256>(getHkdfPrefix());
    case CipherSuite::TLS_AES_256_GCM_SHA384:
      return KeyDerivationImpl::make<Sha384>(getHkdfPrefix());
    case CipherSuite::TLS_AEGIS_256_SHA512:
      return KeyDerivationImpl::make<Sha512>(getHkdfPrefix());
    default:
      throw std::runtime_error("ks: not implemented");
  }
}

std::unique_ptr<HandshakeContext> OpenSSLFactory::makeHandshakeContext(
    CipherSuite cipher) const {
  switch (cipher) {
    case CipherSuite::TLS_CHACHA20_POLY1305_SHA256:
    case CipherSuite::TLS_AES_128_GCM_SHA256:
    case CipherSuite::TLS_AES_128_OCB_SHA256_EXPERIMENTAL:
    case CipherSuite::TLS_AEGIS_128L_SHA256:
      return std::make_unique<HandshakeContextImpl<Sha256>>(getHkdfPrefix());
    case CipherSuite::TLS_AES_256_GCM_SHA384:
    case CipherSuite::TLS_AEGIS_256_SHA512:
      return std::make_unique<HandshakeContextImpl<Sha384>>(getHkdfPrefix());
    default:
      throw std::runtime_error("hs: not implemented");
  }
}

std::unique_ptr<PeerCert> OpenSSLFactory::makePeerCert(
    CertificateEntry certEntry,
    bool /*leaf*/) const {
  return CertUtils::makePeerCert(std::move(certEntry.cert_data));
}

} // namespace openssl
} // namespace fizz
