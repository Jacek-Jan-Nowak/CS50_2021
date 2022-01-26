-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
SELECT name,  transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2020;
SELECT activity, license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND year = 2020;
SELECT transaction_type, amount, account_number  FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2020 AND atm_location = "Fifer Street";
SELECT caller, receiver  FROM phone_calls WHERE  day = 28 AND month = 7 AND year = 2020 AND duration < 60;

SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE courthouse_security_logs.day = 28 AND courthouse_security_logs.month = 7 AND courthouse_security_logs.hour = 10 AND courthouse_security_logs.year = 2020 AND courthouse_security_logs.activity = "exit"
AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2020 AND phone_calls.duration < 60
AND  atm_transactions.day = 28 AND  atm_transactions.month = 7 AND  atm_transactions.year = 2020 AND atm_transactions.transaction_type = "withdraw" AND atm_transactions.atm_location = "Fifer Street";

SELECT * FROM flights
JOIN airports on airports.id = flights.origin_airport_id
WHERE airports.city = "Fiftyville" AND flights.year = 2020 AND flights.month = 7 AND flights.day = 29
ORDER BY flights.hour, flights.minute ASC;

SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports on airports.id = flights.origin_airport_id
WHERE airports.city = "Fiftyville" AND flights.year = 2020 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8;

SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2020 AND phone_calls.duration < 60;

SELECT * FROM airports WHERE id = 4;

SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
-- JOIN phone_calls ON phone_calls.receiver = people.phone_number
AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2020 AND phone_calls.duration < 60 AND phone_calls.caller = (SELECT phone_number FROM people WHERE name = "Ernest");


