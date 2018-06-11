# icpc
## ICPC の過去問とか模擬問題を解いたら振り返りの意味を込めて載せていく。
### 以下、問題を解いた時のモチベーションと反省
#### 世界の天秤（150）
* getlineの使い方 → getline(cin , s)
* OR演算子とAND演算子について  
 * OR演算子は、左側がFalseなら右側も評価する。そうでないならば評価しない。
 *  AND演算子は、左側がTrueなら右側も評価する。そうでないならば評価しない。
 * このように出来るだけ計算量が少なくなるような動作をしている。
* 今回は、OR演算子の左側にstack.top()を置いてしまったのが原因だった。これからは演算子のどちら側に置くのかを意識しようと思う。
#### お姫様の嫁入り（150）
* 単純に単位あたりの期待値が同じの区間をまとめた配列を作って、配列から予算をループ回して引いていくだけ。
#### 君のプライバシーを守れ！（150）
* vector<pair<int, int> > v; が正しい。pair角括弧、　２重角括弧の右はスペース！　二度と間違わないように！
* この問題は、個人が持っている情報と漏洩した情報の一致数で１次判断して、その次に誰も持ってない情報が漏洩情報に含まれるかどうかで2次判断した。
#### Matuzaki数(150)
* エラトステネスの篩使うだけ。
* 反省点としては、無駄なく素数を選ぼうとして失敗してしまったことが挙げられる。入力が大きいケースになると足りなくなることがあるので何個選んでも良いということがわかっているなら予備として多めに持っておく。
#### 王様の視察(150)
* ループ型（円形？）のデータ構造を実装すれば条件分岐でごちゃごちゃしたコードを書かなくてもよかった。今回は、円を切って伸ばした時の長さが短かったのでこれが最善だと思う。この一次元配列を拡張する手法は今回の収穫だった。
* 基礎的な知識としてa~zとA~Zは連番になっていない。なので a-26 == A とはならないので注意。今回の問題を難しくしている要因はこれだと思う。
* 今回、十分に紙の上で場合分けしなかったので一つ状態を見逃してしまった。最近、紙に書かなくても長いコードを組み立てることができるようになってきたが基本を忘れてはいけないなと思った。
#### 整長方形
* 全探索して条件に合致するたび、対角の距離、高さ、横幅をvectorに格納して、最後にソートするだけ。
* ３つ要素を格納するvectorは、vector<int, make_pair<int, int> > > v; と宣言すれば作れる。どうやらclangでは右側で＞を連続で使用する時、間にスペースを入れなければいけないらしい。気をつけよう。
