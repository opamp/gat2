gat2
====

**about**  
gat2はgatの続編です。前作のgatがあまりにもバグが多かったので全部作りなおしてます。  
主に自分がカップ麺作るときとか、時間を測って勉強するときなどに使えるようにつくってます。  



![alt text](http://dl.dropbox.com/u/23369413/pictures/gat2/png/gat1.png)  
ArchLinux(のKDE環境)での動作画像

**Dependence**   
[Qt](http://qt.nokia.com/).
License is [LGPLv2](http://www.gnu.org/licenses/lgpl-2.1.html)   
    
**build**  
buildするときにはcmakeを使ってビルドしてください。Qt4が必要です。  
現在MacOSX Lion対応中です。あと、MacOSXバイナリにも修正が必要のようなので一旦MacOSXバイナリの配布を中止します。   
よってMacとLinuxを利用している方はビルドして利用することができます。  

Qtのサイトから入手可能なQt Library 4.8を使った場合、gatをビルドしても起動時にセグメンテーション違反となり動作しなかった。
が、Qtをソースコードからビルドしインストール後、そのQtを使ってビルドした場合Lion上でも正しく動作することを確認した。
ただ、phononがおかしいのか音声アラートが動作しない。  

**Note**  
Mac,Windowsで動作テスト完了. 正常に音声が再生できるようなので2.3.0リリース。  
対応形式はOSによって異なる(Phononを使っているため)    
wavなら大体のOSで利用可能だと思う。  
MacOSXならm4aなども再生可能。  


Windows7環境でテストして頂いたところ、幾つかバグらしきものが発見されているようです。  
Windows7はうちに環境がないので確認や訂正ができません...   

  
**LICENSE**    
BSDライセンスです


Copyright (c) 2011-2012, opamp
All rights reserved.

Redistribution and use in source and binary forms, with or without  
modification, are permitted provided that the following conditions are met:  
    * Redistributions of source code must retain the above copyright  
      notice, this list of conditions and the following disclaimer.  
    * Redistributions in binary form must reproduce the above copyright  
      notice, this list of conditions and the following disclaimer in the  
      documentation and/or other materials provided with the distribution.  
    * Neither the name of the <organization> nor the  
      names of its contributors may be used to endorse or promote products  
      derived from this software without specific prior written permission.  
  
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
DISCLAIMED. IN NO EVENT SHALL cHRISTOPHER SÖLLINGER BE LIABLE FOR ANY  
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
