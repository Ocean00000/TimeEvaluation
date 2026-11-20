# TimeEvaluation (Windows)

Windows で利用可能な時刻取得 API を `std::chrono` 互換のカスタムクロックとしてラップし、その**分解能（Resolution）**と**レイテンシ（Latency）**を計測・評価する C++ プロジェクトです。

## 概要

以下のクロックを対象に計測を行います。

| クロック | API | 単位 |
|---|---|---|
| `system_clock` | C++ 標準 | ナノ秒 |
| `steady_clock` | C++ 標準 | ナノ秒 |
| `GetSystemTimePreciseAsFileTime_function_clock` | `GetSystemTimePreciseAsFileTime` | ナノ秒 |
| `QueryPerformanceCounter_function_clock` | `QueryPerformanceCounter` | ナノ秒 |
| `timespec_get_function_clock` | `timespec_get` | ナノ秒 |
| `clock_function_clock` | `clock()` | ミリ秒 |
| `GetSystemTimeAsFileTime_function_clock` | `GetSystemTimeAsFileTime` | マイクロ秒 |
| `GetTickCount_function_clock` | `GetTickCount` | ミリ秒 |
| `GetTickCount64_function_clock` | `GetTickCount64` | ミリ秒 |
| `timeGetTime_function_clock` | `timeGetTime` | ミリ秒 |
| `time_function_clock` | `time()` | 秒 |

## プロジェクト構成

| ファイル | 説明 |
|---|---|
| `TimeEvaluation/TimeEvaluation.cpp` | エントリポイント。計測処理と結果出力を行う |
| `TimeEvaluation/FunctionClock.hpp` | 各 API を利用したカスタムクロックの定義 |
| `TimeEvaluation/TimerName.hpp` | クロックの表示名を取得するユーティリティ |
| `TimeEvaluation/Unit.hpp` | 計測単位の表示名を取得するユーティリティ |

## 動作環境

- Windows
- Visual Studio（C++17 以上を想定）
- Windows SDK（`Windows.h`, `mmsystem.h` を使用）

## ビルドと実行

1. `TimeEvaluation.sln` を Visual Studio で開きます。
2. ソリューションをビルドします。
3. 生成された実行ファイルを実行します。

実行すると、以下のような形式で結果が標準出力に出力されます。

```
Timer,Resolution,Unit,Latency,Unit
<クロック名>,<分解能>,<単位>,<レイテンシ>,<単位>
```

## 注意事項

- 計測中はプロセスの優先度を `ABOVE_NORMAL_PRIORITY_CLASS` に引き上げ、計測後に `NORMAL_PRIORITY_CLASS` に戻します。これは計測精度を上げるための措置です。
- `timeGetTime` の計測前に `timeBeginPeriod(1)` を呼び出し、タイマー分解能を 1ms に設定しています。
- 本プロジェクトは Windows 固有の API に依存しているため、他プラットフォームでは動作しません。
