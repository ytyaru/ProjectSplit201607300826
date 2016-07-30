# このソフトウェアについて #

ProjectSplit201607300826は私個人が学習目的で作成したソフトウェアです。

プロジェクトは.libに分割するとファイルサイズが肥大化します。
そこで、.libにせずにソースコードのまま、VC++のフィルタとディレクトリと名前空間で分割しました。

# 開発環境 #

* Windows XP SP3
* C++/Win32
* Visual C++ 2010 Express

# 分割方法 #

* プロジェクトはWindowsアプリケーション1つだけにする
* プロジェクトファイル上でフォルダ作成し、分割する
* ファイルシステム上にてディレクトリ配置する
* LibraryとFramework部分に名前空間を設定した

追加インクルードディレクトリの設定が必要です。
.libファイルが作成されなくなり、exeファイルだけなのでファイルサイズが小さいです。

ソースコードは[MultiWindowCreatorClass201607261835](https://github.com/ytyaru/MultiWindowCreatorClass201607261835)をベースに、いくつか修正しました。

# イメージ #

## プロジェクトディレクトリ構造 ##

![プロジェクトディレクトリ構造](https://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160730/20160730155126.png)

## ディレクトリ構造 ##

![ディレクトリ構造](https://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160730/20160730155152.png)

## 実行 ##

![完成図](https://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160726/20160726213827.png)

# ライセンス #

このソフトウェアはCC0ライセンスです。

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)
