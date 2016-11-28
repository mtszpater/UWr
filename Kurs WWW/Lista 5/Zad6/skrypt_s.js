/**
 * Generator jest lepszy od iteratora, ponieważ w iteratorze najpierw musialbym wygenerowac tablice z liczbami pierwszymi, a pozniej
 * po niej iterowac, a w generatorze mogę "w locie" generowac kolejna liczbe pierwsza, wieksza od aktualnie wygenerowanej.
 */
function* prime(){
    var x = 1;
    while (true){
        x = next(x);
        yield x;
    }
}


function next( value )
{
    var now = value +1;
    while ( ! checkPrime (now) ) {
        now += 1;
    }
    return now;
}
function checkPrime(value){

    if(value < 2)
    {
        return false;
    }

    for (i = 2; i * i <= value; i++) {

        if (value% i == 0) {

            return false;
        }
    }
    return true;


}

var value=0;
var sequence = prime();
console.log(sequence.next().value);     // 2
console.log(sequence.next().value);     // 3
console.log(sequence.next().value);     // 5
console.log(sequence.next().value);     // 7
console.log(sequence.next().value);     // 11