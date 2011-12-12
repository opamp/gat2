gat2
====

**about**  
gat2はgatの続編です。前作のgatがあまりにもバグが多かったので全部作りなおしてます。  
主に自分がカップ麺作るときとか、時間を測って勉強するときなどに使えるようにつくってます。  


![alt text](http://dl.dropbox.com/u/23369413/pictures/gat2/png/gat.png)
ArchLinuxでの動作画像


**build**  
buildするときにはcmakeを使ってビルドしてください。Qt4が必要です。  
Windows,Macは基本的に適当な間隔でバイナリをDownloadsにアップデートしてるのでそれを利用することもできます。  
Linuxにはバイナリを用意していないのでソースコードをDLしてビルドしてください。  

**Note**  
includeの問題は解決した。あとは音の問題 Linux環境上では音が途切れstdoutにエラー出力がされてしまいWindowsではおそらく今も音がならない。  
また、カスタムタイマーが未実装なので音声系の問題が解決したら実装

**LICENSE**  
BSDライセンスです


Copyright (c) 2011, opamp
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
