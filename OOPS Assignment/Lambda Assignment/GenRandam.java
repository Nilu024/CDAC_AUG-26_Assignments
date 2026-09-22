package com.Lambda;

import java.util.Random;
import java.util.function.Supplier;

public class GenRandam {

	public static void main(String[] args) {
		
		Supplier<Integer> randomNumber = () -> {
			Random random = new Random();
			
			return random.nextInt(900) + 100;
		};
		
		System.out.println("Random Number: " + randomNumber.get());
	}

}
