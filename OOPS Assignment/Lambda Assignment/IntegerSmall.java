package com.Lambda;

import java.util.function.Function;

public class IntegerSmall {

	public static void main(String[] args) {
		
		int[] numbers = {45, 12, 78, 23, 67, 91, 34};
		
		Function<int[], Integer> smallest = arr -> {
			int max = arr[0];
			
			for (int i : arr) {
				if(i < max)
					max = i;
			}
			
			return max;
		};
		
		System.out.println("Smallest number: " + smallest.apply(numbers));
	}

}
