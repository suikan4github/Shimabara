# Shimabara
Archive of the ADAU1361A CODEC Driver for mbed.
## はじめに
shimabaraは、mbedからオーディオ･コーデックのハードウェアを操作するクラス･ライブラリです。このライブラリは[雲仙オーディオ･フレームワーク](https://github.com/suikan4github/Unzen)と共に使うことを想定して開発しましたが、独立して使うことも可能です。

## 使い方

shimabaraは BaseAudioCodec, ADAU1361, UMB_ADAU1361Aの三つのクラスを定義しています。いずれのクラスも名前空間simabaraに属しています。実際のアプリケーションで使用するのはshimabara::UMB_ADAU1361Aだけで、このクラスはアクアシグナルの[UMB-ADAU1361-A](http://dsps.shop-pro.jp/?pid=82798273)に対応しています。ヘッダーファイルは umb_adau1361a.hです。

shimabara::UMB_ADAU1361Aのコンストラクタは三つの引数を受け取ります。

- Fs はサンプル周波数です。これはenum Fs_type型の引数で、やはり名前空間shimabaraに属しています。
- controller はADAU1361Aが接続されているI2Cポートに対応するI2Cオブジェクトを与えます。shimabaraはこのポートを通してCODECと通信します。
- Addrには、コーデックのI2Cアドレスを与えます。現時点ではこの引数は0x38固定です。 

コンストラクタでオブジェクトを初期化したら、start()メソッドを呼んでください。これでshimabaraはコーデックと通信し、I2Sモードでの動作が始まります。

## ライセンス
このプロジェクトは[MITライセンス](LICENSE)に基づいて公開しています。