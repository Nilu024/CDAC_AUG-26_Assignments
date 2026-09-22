package com.BigProject;

import java.util.Random;
import java.util.function.Supplier;

public class RandomOTP {

	public static void main(String[] args) {
		
		Supplier<String> otp = () -> {
			Random random = new Random();
			
			String vowels = "AEIOU";
			
			char firstChar = vowels.charAt(random.nextInt(5));
			String result = "" + firstChar;
			
			for (int i = 0; i < 4; i++) {
				result += random.nextInt(10);
				
			}
			
			return result;
		};
		
		System.out.println("OTP: " + otp.get());
	}

}
