"use strict";
window.onload = function load()
{
	document.getElementById('form').onsubmit = checkForm;
} 

function checkForm()
{
	// Używanie zmiennej bez jej wcześniejszego zadeklarowania.
        error = false;
        if (!peselCheck()){
            error = true;
        }
        if (error){
            return false;
        }
        return true;
}

function peselCheck() {
	   //Używanie słowa kluczowego zarezerwowanego na przyszłość jako nazwy zmiennej lub funkcji.
	    var public=document.getElementById('pesel');
            var regex = /^[0-9]{11}$/;
            if (regex.test(public.value) == false) {
            	public.style.border = "1px solid #FF0000";
               return false;
            }
         	public.style.border = "1px solid #00E600";
         	//Usuwanie zmiennej, funkcji lub argumentu.
         	delete public;
        }

/*
-> Po pierwsze, eliminuje niektóre „pułapki” starszych wersji języka – uniemożliwia stosowanie niewłaściwych konstrukcji, które do tej pory nie kończyły się jednak błędem. 
-> Po drugie, naprawia on błędy, które utrudniały silnikom JavaScriptu dokonywanie optymalizacji: kod działający w trybie ścisłym może być wykonywany szybciej niż identyczny kod zwykły. Firefox 4 ogólnie nie optymalizuje jeszcze kodu trybu ścisłego, ale kolejne wersje będą to robić. 
*/
