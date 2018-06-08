# icpc
## ICPC の過去問とか模擬問題を解いたら振り返りの意味を込めて載せていく。
### 以下、問題を解いた時のモチベーションと反省
#### 世界の天秤
* getlineの使い方 → getline(cin , s)
* OR演算子とAND演算子について  
 * OR演算子は、左側がFalseなら右側も評価する。そうでないならば評価しない。
 *  AND演算子は、左側がTrueなら右側も評価する。そうでないならば評価しない。
 * このように出来るだけ計算量が少なくなるような動作をしている。
* 今回は、OR演算子の左側にstack.top()を置いてしまったのが原因だった。これからは演算子のどちら側に置くのかを意識しようと思う。

