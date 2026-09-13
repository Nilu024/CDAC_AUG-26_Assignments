package com.evaluate;

import java.util.Scanner;

public class Validates {
	Scanner sc = new Scanner(System.in);
	
	private int day;
	private int month;
	private int year;
	
	private int maxDays() {
		int days;
		 switch (this.month) {
	        case 2:
	            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
	                days = 29;
	            } else {
	                days = 28;
	            }
	            break;

	        case 4:
	        case 6:
	        case 9:
	        case 11:
	            days = 30;
	            break;

	        default:
	            days = 31;
	    }
		
		return days;
		
	}
	
	public int getDay() {
		return day;
	}
	
	public int getMonth() {
		return month;
	}
	
	public int getYear() {
		return year;
	}
	
	
	public void setYear() {
		System.out.print("Enter Year: ");
		int years = sc.nextInt();
		if (years >= 1) {
		    this.year = years;
		} else {
		    System.out.println("Invalid Year Entered.");
		}
	}

	public void setMonth() {
		System.out.print("Enter Month: ");
		int months = sc.nextInt();
		if (months >= 1 && months <= 12) {
		    this.month = months;
		} else {
		    this.month = 1;
		    System.out.println("Invalid Month Entered.");
		}
	}
	
	public void setDay() {

		System.out.print("Enter Day: ");
		int days = sc.nextInt();

	    int maxDays = maxDays();

	    if (days >= 1 && days <= maxDays) {
	        this.day = days;
	    } else {
	        this.day = 1;
	        System.out.println("Invalid Day Entered.");
	    }
	}
	
	public void addYears() {

		System.out.print("Enter Years want to add: ");
		int num = sc.nextInt();
		
		this.year = year + num;
	}
	
	public void addMonths() {

		System.out.print("Enter months want to add: ");
		int num = sc.nextInt();
		
		int totalMonths = num + month;
		int years = totalMonths / 12;
		int remainingMonths = totalMonths % 12;
		
		this.year = year + years;
		this.month = remainingMonths;
		
		System.out.println("No of days : " + maxDays());
		if(this.day > maxDays()) {
			this.day -= maxDays();
			this.month = remainingMonths + 1;
		}
	}
	
	public void addDays() {

		System.out.print("Enter Days to add: ");
		int num = sc.nextInt();

	    while (num > 0) {

	        int max = maxDays();
	        int remaining = max - day;

	        if (num <= remaining) {
	            day += num;
	            num = 0;
	        } else {
	            num -= (remaining + 1);
	            day = 1;

	            month++;

	            if (month > 12) {
	                month = 1;
	                year++;
	            }
	        }
	    }
	}
	
	public void display() {
		System.out.println("Date : " + day + "/" + month + "/" + year);
	}

}
