gat2
====

##about   
gat2はgatの続編です。前作のgatがあまりにもバグが多かったので全部作りなおしてます。  
主に自分がカップ麺作るときとか、時間を測って勉強するときなどに使えるようにつくってます。  
   

![alt text](http://dl.dropbox.com/u/23369413/pictures/gat2/png/gat.png)  
ArchLinux(Xfce)での動作画像  

##Download   
Binary for Windows(32bit)   
[Download](https://dl.dropboxusercontent.com/u/23369413/oss/Gat2-win32.zip)   
   
Test Binary for OSX Mountain Lion   
[Download](http://dl.dropbox.com/u/23369413/oss/gat.dmg)   

##Dependencies
[Qt5](http://qt.nokia.com/).
License is [LGPLv2](http://www.gnu.org/licenses/lgpl-2.1.html)   
You cannot use Qt4.  
    
##Building gat
ビルドするにはCMake(2.8.10 or later)がビルドする環境で利用可能である必要があります。CMakeは以下のURLからDLできます。   

http://www.cmake.org/   
   

以下にはCMakeとgcc,GNUMakeを使ってビルドするコマンドの例を示します。また、gat2はQt5に依存しています。   
また、ArchLinuxではAURを使ってビルド、インストールすることもできます。Yaourtをインストールしているなら以下のコマンドを入力するだけです。

	sudo yaourt -S gat2   

(設定によってはいくつかの質問が対話的にされることがあります)   

####ビルド例   
#####まずソースコードをDLします.   
	
	$ git clone git://github.com/opamp/gat2.git   

DLはgitがなくてもgithubからzipなどでDLできるのでそれを利用しても大丈夫です。   

#####次に、作業用ディレクトリを作りcmakeを実行します。   

	$ cd gat2   
	$ git checkout -b build 2.6.0  
	$ mkdir build   
	$ cd build   

として作業用ディレクトリを作り   

	$ cmake ../   

としてcmakeを実行します。Qt4はこの時点で探されるのでインストールされていなかった場合はエラーになります。   

#####GNUMakeを使ってビルドする   

	$ make   

とします。  するとビルドが始まるのでしばらくまちます。  
しばらくするとプロンプトに戻りgatという実行可能ファイルが完成しています。これでビルド完了です。   
必要に応じてインストールしてください   

	$ (sudo) make install   

Macの場合はgat.appというファイルになっているのでmake installは利用できません。手動で /Applications などにコピーしてください.   

また、Windowsの場合はMinGWなどを使ってビルドできると思います。(VC++は推奨しません)   
Windowsの場合cmakeはコマンドラインよりGUIツールを利用したほうがいいかもしれないです。   
    
    
##LICENSE  
BSDライセンスです   
   
Copyright (c) 2011-2013 opamp   
All rights reserved.   
   
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  *Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.   
  *Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.   
  *Neither the name of the opamp nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.   
   
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   
