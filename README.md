# TimeEvaluation

各プラットフォームで利用可能な時刻取得 API を `std::chrono` 互換のカスタムクロックとしてラップし、その**分解能（Resolution）**と**レイテンシ（Latency）**を計測・評価する C++ プロジェクトです。

## 概要

時刻取得 API は種類によって精度・コストが大きく異なります。本プロジェクトでは各 API を統一インターフェースのクロックとして実装し、以下の2指標を CSV 形式で出力することで横断的な比較を可能にします。

- **Resolution（分解能）** : クロックの値が変化する最小の時間間隔
- **Latency（レイテンシ）** : `now()` 呼び出し1回あたりの所要時間

## プロジェクト構成

| ディレクトリ | プラットフォーム | 使用 API |
|---|---|---|
| `Mac/` | macOS | `clock_gettime`, `timespec_get`, `gettimeofday`, `clock()`, `time()` |
| `Windows/` | Windows | `GetSystemTimePreciseAsFileTime`, `QueryPerformanceCounter`, `timespec_get`, `GetTickCount64`, `timeGetTime` など |

詳細は各ディレクトリの README を参照してください。

- [Mac/README.md](Mac/README.md)
- [Windows/README.md](Windows/README.md)

## 出力形式

いずれのプロジェクトも、実行すると以下の CSV 形式で標準出力に結果を出力します。

```
Timer,Resolution,Unit,Latency,Unit
<クロック名>,<分解能>,<単位>,<レイテンシ>,<単位>
```
