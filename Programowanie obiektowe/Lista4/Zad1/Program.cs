using System;
using System.Collections;

interface IStream <T>
{
	T next();
}

public class PrimeStreamEnum : IEnumerator
{
	private int now = 1;
	PrimeStream pm;

	public PrimeStreamEnum(int _n)
	{
		now = _n;
		pm = new PrimeStream ();
	}

	public bool MoveNext()
	{
		now = pm.next ();

		return (now < int.MaxValue);
	}

	public void Reset()
	{
		now = 1;
	}

	object IEnumerator.Current
	{
		get
		{
			return Current;
		}
	}

	public int Current
	{
		get
		{
			try
			{
				return now;
			}
			catch (IndexOutOfRangeException)
			{
				throw new InvalidOperationException();
			}
		}
	}
}


class PrimeStream : IEnumerable, IStream <int>{

	protected int now;
	private int _length;


	/* Konstruktor */
	public PrimeStream(){
		now = 1;
		_length = 0;
	}
		
	/* Właściwości */
	public int Length
	{
		get
		{
			return _length;
		}
	}

	public int this[int index]
	{
		get
		{
			int tmp_n = now;
			int tmp_l = _length;

			int i = 0;

			while (i < index) {
				next ();
				++i;
			}

			int to_return = now;

			now = tmp_n;
			_length = tmp_l;

			return to_return;
		}
	}

	public override string ToString ()
	{
		return string.Format ("Aktualna wartosc {0}", now);
	}


	/* Metody publiczne */
	virtual public bool eos(){
		if(now + 1 < int.MaxValue )
			return false;

		return true;
	}
		
	public int next(){
		if (eos ()) {
			return now; 
		}

		now = now + 1;
		while (!checkPrime ()) 
			now = now + 1;

		++_length;
		return now;
	}
		
	bool checkPrime(){

		if(this.now < 2)
		{
			return false;
		}

		for (int i = 2; i * i <= this.now; i++) {

			if (this.now % i == 0) {

				return false; 
			}
		}
		return true;


	}

	/* Numerator */
	IEnumerator IEnumerable.GetEnumerator()
	{
		return (IEnumerator) GetEnumerator();
	}

	public PrimeStreamEnum GetEnumerator()
	{
		return new PrimeStreamEnum(now);
	}


}

class RandomWordStream : IStream <string> {

	PrimeStream prime;
	Random random;

	public RandomWordStream(){
		prime = new PrimeStream ();
		random = new Random();
	}


	public string next(){


		var chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		var stringChars = new char[prime.next()];


		for (int i = 0; i < stringChars.Length; i++)
		{
			stringChars[i] = chars[random.Next(chars.Length)];
		}

		var finalString = new String(stringChars);

		return finalString;
	}
}



namespace L4Z1
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			PrimeStream t = new PrimeStream ();


			Console.WriteLine (t[10]);
			Console.WriteLine ("Dlugosc: {0} ", t.Length);
			t.next ();
			Console.WriteLine ("Dlugosc: {0} ", t.Length);
			Console.WriteLine (t[5]);

			Console.WriteLine (t);
			Console.WriteLine (t[0]);
			t.next ();
			t.next ();
			t.next ();
			t.next ();
			Console.WriteLine ("Dlugosc: {0} ", t.Length);


			/*foreach (int p in t)
				Console.WriteLine(p);*/




			RandomWordStream rs = new RandomWordStream ();

			Console.WriteLine (rs.next ());
			Console.WriteLine (rs.next ());
			Console.WriteLine (rs.next ());




		}
	}
}


