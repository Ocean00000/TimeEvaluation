# TimeEvaluation (Mac)

macOS で利用可能な時刻取得 API を `std::chrono` 互換のカスタムクロックとしてラップし、その**分解能（Resolution）**と**レイテンシ（Latency）**を計測・評価する C++ プロジェクトです。

## 概要

以下のクロックを対象に計測を行います。

| クロック | API | 単位 |
|---|---|---|
| `system_clock` | C++ 標準 | ナノ秒 |
| `steady_clock` | C++ 標準 | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_REALTIME>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_MONOTONIC>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_MONOTONIC_RAW>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_MONOTONIC_RAW_APPROX>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_UPTIME_RAW>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_UPTIME_RAW_APPROX>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_PROCESS_CPUTIME_ID>` | `clock_gettime` | ナノ秒 |
| `clock_gettime_function_clock<CLOCK_THREAD_CPUTIME_ID>` | `clock_gettime` | ナノ秒 |
| `timespec_get_function_clock` | `timespec_get` | ナノ秒 |
| `clock_function_clock` | `clock()` | マイクロ秒 |
| `gettimeofday_function_clock` | `gettimeofday` | マイクロ秒 |
| `time_function_clock` | `time()` | 秒 |

## プロジェクト構成

| ファイル | 説明 |
|---|---|
| `TimeEvaluation/main.cpp` | エントリポイント。計測処理と結果出力を行う |
| `TimeEvaluation/FunctionClock.hpp` | 各 API を利用したカスタムクロックの定義 |
| `TimeEvaluation/TimerName.hpp` | クロックの表示名を取得するユーティリティ |
| `TimeEvaluation/Unit.hpp` | 計測単位の表示名を取得するユーティリティ |

## 動作環境

- macOS
- Xcode（C++17 以上を想定）
- POSIX API（`time.h`, `sys/time.h` を使用）

## ビルドと実行

1. `TimeEvaluation.xcodeproj` を Xcode で開きます。
2. プロジェクトをビルドします。
3. 生成された実行ファイルを実行します。

実行すると、以下のような形式で結果が標準出力に出力されます。

```
Timer,Resolution,Unit,Latency,Unit
<クロック名>,<分解能>,<単位>,<レイテンシ>,<単位>
```
