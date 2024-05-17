/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.facebook.thrift.protocol;

import static org.junit.Assert.assertEquals;

import com.facebook.nifty.header.protocol.TFacebookCompactProtocol;
import com.facebook.thrift.test.EveryLayout;
import com.facebook.thrift.test.JustABinary;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.Lists;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.ByteBufAllocator;
import io.netty.buffer.Unpooled;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.util.concurrent.ThreadLocalRandom;
import org.apache.thrift.protocol.TCompactProtocol;
import org.apache.thrift.transport.TIOStreamTransport;
import org.junit.Test;

public class ByteBufTCompactProtocolTest {
  private static final byte[] binary;

  static {
    binary = new byte[1024];
    ThreadLocalRandom.current().nextBytes(binary);
  }

  @Test
  public void test() {}

  @Test
  public void testSerializeBinary() throws Exception {
    JustABinary aBinary = new JustABinary.Builder().setABinary(binary).build();

    ByteBuf byteBuf = ByteBufAllocator.DEFAULT.heapBuffer();
    ByteBufTCompactProtocol byteBufTCompactProtocol = new ByteBufTCompactProtocol();
    byteBufTCompactProtocol.wrap(byteBuf);

    aBinary.write0(byteBufTCompactProtocol);

    ByteArrayInputStream bis =
        new ByteArrayInputStream(byteBuf.array(), byteBuf.arrayOffset(), byteBuf.readableBytes());
    TIOStreamTransport tios = new TIOStreamTransport(bis);
    TCompactProtocol binaryProtocol = new TCompactProtocol(tios);

    JustABinary fromBytes = JustABinary.read0(binaryProtocol);

    assertEquals(fromBytes, aBinary);
  }

  @Test
  public void testSerialize() throws Exception {
    EveryLayout everyLayout =
        new EveryLayout.Builder()
            .setABool(true)
            .setADouble(Double.MAX_VALUE)
            .setAFloat(Float.MAX_VALUE)
            .setAByte((byte) 1)
            .setAInt(Integer.MAX_VALUE)
            .setAShort(Short.MAX_VALUE)
            .setALong(Long.MAX_VALUE)
            .setAList(Lists.newArrayList("1", "2", "3"))
            .setAMap(ImmutableMap.of(1, "value"))
            .setASet(ImmutableSet.of("1", "2", "3"))
            .setAListOfLists(
                Lists.newArrayList(
                    Lists.newArrayList("1", "2", "3"),
                    Lists.newArrayList("1", "2", "3"),
                    Lists.newArrayList("1", "2", "3")))
            .setASetOfSets(
                ImmutableSet.of(
                    ImmutableSet.of("1", "2", "3"),
                    ImmutableSet.of("4", "5", "6"),
                    ImmutableSet.of("7", "8", "9")))
            .setAMapOfLists(
                ImmutableMap.of(Lists.newArrayList(1, 2, 3), Lists.newArrayList(1, 2, 3)))
            .setABinary(binary)
            .build();

    ByteBuf byteBuf = ByteBufAllocator.DEFAULT.heapBuffer();
    ByteBufTCompactProtocol byteBufTCompactProtocol = new ByteBufTCompactProtocol();
    byteBufTCompactProtocol.wrap(byteBuf);

    everyLayout.write0(byteBufTCompactProtocol);
    ByteArrayInputStream bis =
        new ByteArrayInputStream(byteBuf.array(), byteBuf.arrayOffset(), byteBuf.readableBytes());
    TIOStreamTransport tios = new TIOStreamTransport(bis);
    TFacebookCompactProtocol binaryProtocol = new TFacebookCompactProtocol(tios);

    EveryLayout fromBytes = EveryLayout.read0(binaryProtocol);

    assertEquals(fromBytes, everyLayout);
  }

  @Test
  public void testDeserialize() throws Exception {
    EveryLayout everyLayout =
        new EveryLayout.Builder()
            .setABool(true)
            .setADouble(Double.MAX_VALUE)
            .setAFloat(Float.MAX_VALUE)
            .setAByte((byte) 1)
            .setAInt(Integer.MAX_VALUE)
            .setAShort(Short.MAX_VALUE)
            .setALong(Long.MAX_VALUE)
            .setAList(Lists.newArrayList("1", "2", "3"))
            .setAMap(ImmutableMap.of(1, "value"))
            .setASet(ImmutableSet.of("1", "2", "3"))
            .setAListOfLists(
                Lists.newArrayList(
                    Lists.newArrayList("1", "2", "3"),
                    Lists.newArrayList("1", "2", "3"),
                    Lists.newArrayList("1", "2", "3")))
            .setASetOfSets(
                ImmutableSet.of(
                    ImmutableSet.of("1", "2", "3"),
                    ImmutableSet.of("4", "5", "6"),
                    ImmutableSet.of("7", "8", "9")))
            .setAMapOfLists(
                ImmutableMap.of(Lists.newArrayList(1, 2, 3), Lists.newArrayList(1, 2, 3)))
            .setABinary(binary)
            .build();

    ByteArrayOutputStream bos = new ByteArrayOutputStream();
    TIOStreamTransport tios = new TIOStreamTransport(bos);
    TFacebookCompactProtocol compactProtocol = new TFacebookCompactProtocol(tios);

    everyLayout.write0(compactProtocol);

    ByteBufTCompactProtocol byteBufTBinaryProtocol = new ByteBufTCompactProtocol();
    byteBufTBinaryProtocol.wrap(Unpooled.wrappedBuffer(bos.toByteArray()));

    EveryLayout fromBytes = EveryLayout.read0(byteBufTBinaryProtocol);

    assertEquals(fromBytes, everyLayout);
  }

  @Test
  public void testDeserializeBinary() {
    JustABinary aBinary = new JustABinary.Builder().setABinary(binary).build();

    ByteArrayOutputStream bos = new ByteArrayOutputStream();
    TIOStreamTransport tios = new TIOStreamTransport(bos);
    TCompactProtocol binaryProtocol = new TCompactProtocol(tios);

    aBinary.write0(binaryProtocol);

    ByteBufTCompactProtocol byteBufTBinaryProtocol = new ByteBufTCompactProtocol();
    byteBufTBinaryProtocol.wrap(Unpooled.wrappedBuffer(bos.toByteArray()));

    JustABinary fromBytes = JustABinary.read0(byteBufTBinaryProtocol);

    assertEquals(fromBytes, aBinary);
  }
}
