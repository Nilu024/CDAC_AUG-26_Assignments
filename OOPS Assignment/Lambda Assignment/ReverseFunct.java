package com.Lambda;

import java.util.function.Function;

public class ReverseFunct {

	public static void main(String[] args) {
		
		int[] numbers = {45, 12, 78, 23, 67, 91, 34, 52};
		for (int i : numbers) {
			System.out.print(i + " ");
		}
		
		Function<int[], int[]> reverseArray = arr -> {
			
			int forw = 0;
			int back = arr.length-1;
			while(back > forw) {
				int item = arr[back];
				arr[back] = arr[forw];
				arr[forw] = item;
				
				back--;
				forw++;
			}
			
			return arr;
			
		};
		
		reverseArray.apply(numbers);
		
		System.out.println();
		for (int i : numbers) {
			System.out.print(i + " ");
		}
	}

}
