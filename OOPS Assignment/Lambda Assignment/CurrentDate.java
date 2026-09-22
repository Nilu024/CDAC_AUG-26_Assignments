package com.Lambda;

import java.time.LocalDate;
import java.util.function.Supplier;

public class CurrentDate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Supplier<LocalDate> localDate = () -> LocalDate.now();
		
		System.out.println("Current Date: " + localDate.get());

	}

}
