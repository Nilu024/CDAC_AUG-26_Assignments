package com.CollectLambda;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Function;
import java.util.function.Predicate;

class Transaction {

    private int txId;
    private LocalDate txDate;
    private float txAmount;
    private boolean txStatus;
    private boolean txArrears;

    public Transaction(int txId, LocalDate txDate, float txAmount,
                       boolean txStatus, boolean txArrears) {

        this.txId = txId;
        this.txDate = txDate;
        this.txAmount = txAmount;
        this.txStatus = txStatus;
        this.txArrears = txArrears;
    }

    public int getTxId() {
        return txId;
    }

    public LocalDate getTxDate() {
        return txDate;
    }

    public float getTxAmount() {
        return txAmount;
    }

    public boolean isTxStatus() {
        return txStatus;
    }

    public boolean isTxArrears() {
        return txArrears;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "txId=" + txId +
                ", txDate=" + txDate +
                ", txAmount=" + txAmount +
                ", txStatus=" + txStatus +
                ", txArrears=" + txArrears +
                '}';
    }
}


public class TransactionMain {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        List<Transaction> transactions = new ArrayList<>();

        // Taking input for 5 transactions
        for (int i = 0; i < 1; i++) {

            System.out.println("\nEnter Transaction " + (i + 1));

            System.out.print("Transaction ID: ");
            int id = sc.nextInt();

            System.out.print("Transaction Date (yyyy-mm-dd): ");
            LocalDate date = LocalDate.parse(sc.next());

            System.out.print("Transaction Amount: ");
            float amount = sc.nextFloat();

            System.out.print("Transaction Status (true/false): ");
            boolean status = sc.nextBoolean();

            System.out.print("Transaction Arrears (true/false): ");
            boolean arrears = sc.nextBoolean();

            Transaction tx = new Transaction(
                    id, date, amount, status, arrears
            );

            transactions.add(tx);
        }


        // 1. Transactions where amount > 5000

        Predicate<Transaction> amountGreaterThan5000 =
                tx -> tx.getTxAmount() > 5000;

        System.out.println("\nTransactions with amount > 5000:");

        transactions.stream()
                .filter(amountGreaterThan5000)
                .forEach(System.out::println);


        // 2. Transactions where status is false

        Predicate<Transaction> statusFalse =
                tx -> !tx.isTxStatus();

        System.out.println("\nTransactions with status false:");

        transactions.stream()
                .filter(statusFalse)
                .forEach(System.out::println);


        // 3. Generate amount due

        Function<Transaction, Float> amountDue =
                tx -> tx.isTxArrears()
                        ? tx.getTxAmount()
                          + 500
                          + (tx.getTxAmount() * 0.18f)
                        : tx.getTxAmount();

        System.out.println("\nAmount Due:");

        for (Transaction tx : transactions) {

            System.out.println(
                    "Transaction ID: " + tx.getTxId()
                    + " Amount Due: "
                    + amountDue.apply(tx)
            );
        }

        sc.close();
    }
}
