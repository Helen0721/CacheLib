#!/bin/bash

data_urls=(
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/metaKV/meta_kvcache_traces_1.oracleGeneral.bin.zst" 
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/.other/akamai_lax.oracleGeneral.sample10.zst" 
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/.other/tencent_photo2.oracleGeneral.sample10.zst" 
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/.other/wiki_2019t.oracleGeneral.sample10.zst" 
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/twitter/sample/cluster52.oracleGeneral.sample10.zst" 
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/wiki/wiki_2019t.oracleGeneral.zst" 
	"https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/.other/wiki_2019t.oracleGeneral.sample10.zst"
	)

for data_url in ${data_urls[@]}; do
	echo "downloading $data_url"
	wget -P data/ "$data_url"
done

