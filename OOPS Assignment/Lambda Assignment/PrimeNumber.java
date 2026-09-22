package com.Lambda;

import java.util.function.Predicate;

public class PrimeNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int number = 43;
		
		Predicate<Integer> isPrime = num -> {
			if(num < 2)
				return false;
			
			for (int i = 2; i < num; i++) {
				if(num % i == 0)
					return false;
			}
			
			return true;
		};
		
		System.out.println("Is Prime: " + isPrime.test(number));

	}

}
