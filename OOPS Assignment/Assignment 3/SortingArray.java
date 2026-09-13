package SortingArray;

import java.util.Scanner;

public class SortingArray {
	
	public static void main(String[] args) {
		
//		Scanner sc = new Scanner(System.in);
//		
//		System.out.print("Enter Size : ");
//		int size = sc.nextInt();
//		
//		int arr[] = new int[size];
//		for(int i = 0; i < size; i++) {
//			System.out.print("Enter Element no " + (i+1) + " : ");
//			arr[i] = sc.nextInt();
//		}
		
		int arr[] = {56, 12, 58, 96, 23, 10};
		
		System.out.println("Entered Array : ");
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println("\n====================================");
		
		for(int i = 0; i < arr.length; i++) {
			for(int j = i; j < arr.length; j++) {
				if(arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		
		System.out.println("Sorted Array : ");
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		
		
		System.out.println("\n====================================");
		SumValuesOfArray obj = new SumValuesOfArray();
        int totalValue = obj.sumValues(arr);
        System.out.println("Sum = " + totalValue);
        
        System.out.println("====================================");
        AverageValue avgValue = new AverageValue();
        float average = avgValue.averageValue(totalValue, arr.length);
        System.out.println("Average = " + average);
        
        System.out.println("====================================");
        CopyArray cpa = new CopyArray();
        int newArr[] = cpa.copyArray(arr);
        System.out.print("Copied Array : ");
        for(int it : newArr) {
        	System.out.print(it + " " );
        }
        
        System.out.println("\n====================================");
        MinMaxFromArr minMaxValues = new MinMaxFromArr();
        int minMax[] = minMaxValues.MinMaxValues(newArr);
        System.out.println("Min Value: " + minMax[0]);
        System.out.println("Max Value: " + minMax[1]);
        
        
        System.out.println("====================================");
        ReverseArray reverseArray = new ReverseArray();
        int reverse[] = reverseArray.reverseArray(newArr);
        System.out.print("Reverse Array : ");
        for(int it : reverse) {
        	System.out.print(it + " " );
        }
        
        System.out.println("\n====================================");
        DuplicateValues dupl = new DuplicateValues();
        int numbers[] = {12, 20, 25, 12, 58, 25};
        System.out.print("Original Array : ");
        for(int it : numbers) {
        	System.out.print(it + " " );
        }
        int duplicate[] = dupl.duplicateValues(numbers);
        System.out.print("\nDuplicate values: ");
        for(int it : duplicate) {
        	if(it > 0)
        	System.out.print(it + " " );
        }
		
	}
}
