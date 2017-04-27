// READ + WRITE + TALK = SKILL

/**
 * array.permutation()の追加
 */
(function() {
  var generatePermutation = function(perm, pre, post, n) {
    var elem, i, rest, len;
    if (n > 0)
      for (i = 0, len = post.length; i < len; ++i) {
        rest = post.slice(0);
        elem = rest.splice(i, 1);
        generatePermutation(perm, pre.concat(elem), rest, n - 1);
      }
    else
      perm.push(pre);
  };

  Array.prototype.permutation = function(n) {
    if (n == null) n = this.length;
    var perm = [];
    generatePermutation(perm, [], this, n);
    return perm;
  };
})();

// 0から9までの10個の順列を取得
var perm = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9].permutation();
/**
 * 添字対応
 * 0 1 2 3 4 5 6 7 8 9
 * A D E I K L R S T W
 */
function check (i) {
  var answer = document.getElementById('answer');

  var read = perm[i][6] * 1000 + perm[i][2] * 100 + perm[i][0] * 10 + perm[i][1];
  var write = perm[i][9] * 10000 + perm[i][6] * 1000 + perm[i][3] * 100 + perm[i][8] * 10 + perm[i][2];
  var talk = perm[i][8] * 1000 + perm[i][0] * 100 + perm[i][5] * 10 + perm[i][4];
  var skill = perm[i][7] * 10000 + perm[i][4] * 1000 + perm[i][3] * 100 + perm[i][5] * 10 + perm[i][5];

  if (read + write + talk == skill) {
    console.log(read + ' + ' + write + ' + ' + talk + ' = ' + skill);
    var newp = document.createElement('p');
    newp.innerHTML = read + ' + ' + write + ' + ' + talk + ' = ' + skill;
    answer.appendChild(newp);
  }
}

function main () {
  var answer = document.getElementById('answer');

  while (answer.firstChild) answer.removeChild(answer.firstChild);
  for (var i = 0, l = perm.length; i < l; i++) {
    check(i);
  }
}
