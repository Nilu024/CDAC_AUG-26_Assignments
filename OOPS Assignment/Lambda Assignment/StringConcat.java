package com.Lambda;

import java.util.function.BiFunction;

public class StringConcat {

	public static void main(String[] args) {
		
		BiFunction<String, String, String> conc = (str1, str2) -> str1 + str2;
		
		String result = conc.apply("Hello ", "World");
		
		System.out.println("Concatenated String: " + result);
		}
	}

