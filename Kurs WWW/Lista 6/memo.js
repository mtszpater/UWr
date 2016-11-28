var img = ["1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png", "10.png"];
function shuffle(a) {
    var j, x, i;
    for (i = a.length; i; i--) {
        j = Math.floor(Math.random() * i);
        x = a[i - 1];
        a[i - 1] = a[j];
        a[j] = x;
    }
}
var Imager = (function () {
    function Imager(_imgs, int, int2) {
        this.int = int;
        this.imgs = _imgs;
        this.int2 = int2;
    }
    Imager.prototype.img = function () {
        return "<div id=card" + this.int + "_" + this.int2 + "><img src=" + this.imgs + ">" + "</div>";
    };
    return Imager;
}());
function createImagers() {
    var i, body = "<div id='board'><div id='box'>";
    var array = [];
    for (i = 0; i < img.length; i++) {
        var imager = new Imager(img[i], i, i);
        array.push(imager.img());
    }
    for (i = 0; i < img.length; i++) {
        var imager = new Imager(img[i], i, i + 10);
        array.push(imager.img());
    }
    shuffle(array);
    console.log(array);
    for (i = 0; i < array.length; i++) {
        body = body + array[i];
    }
    body = body + "</div></div>";
    document.body.innerHTML = body;
}
function win() {
    document.body.style.animationDuration = "1s";
    document.body.style.animationName = "winAnimation";
}
createImagers();
//# sourceMappingURL=memo.js.map