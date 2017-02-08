#! /bin/bash

function cToF ()
{
	echo "scale = 2; $1 * 1.8 + 32" | bc
	return
}

function currentTemp ()
{
	temp=`expr $1 \* 4 + 40`
	echo "scale = 2; $temp * 0.25" | bc
	return
}

function lengthInInches ()
{
	lengthI=`expr 12 \* $1 + $2`
	return $lengthI
}

function triangleArea ()
{
	echo "scale = 2; 0.5 * $1 * $2" | bc
	return
}

function sumCoins ()
{
	ans=`expr 25 \* $1 + 10 \* $2 + 5 \* $3 + $4` 
	return $ans
}

function cylinderVolume ()
{
	echo "scale = 2; $1 * $2" | bc
	return
}

function circleArea ()
{
	echo "scale = 2; 3.14 * $1 * $1" | bc
	return
}

echo "Welcome to the Utility Script. Select a number for the calculation you want:"
echo
echo "1) Celsius to Fahrenheit"
echo "2) Cricket Temperature"
echo "3) Length in Inches"
echo "4) Triangle Area"
echo "5) Coin Counter"
echo "6) Cylinder Volume"
echo
read  option

case $option in
	1)
		echo -n "Enter the degree in Celsius: "
		read tempInC
		tempInF=$(cToF $tempInC)
		echo "The temperature is $tempInF degrees F."
		;; 
	2)
		echo -n "Enter the number of chirps heard in 15 seconds: "
		read input
		output=$(currentTemp $input)
		echo "The temperature is $output degrees F."
		;;
	3) 
		echo -n "Enter the number of feet: "
		read numOfFeet
		echo -n "Enter the number of inches: "
		read numOfInch
		lengthInInches $numOfFeet $numOfInch
		echo "The length in inches is $? inches."
		;;
	4)
		echo -n "Enter the length of a triangle's base: "
		read base
		echo -n "Enter the length of a triangle's height: "
		read height
		area=$(triangleArea $base $height)
		echo "The are of the triangle is $area."
		;;
	5)
		echo -n "Enter the number of quarters: "
		read quarter
		echo -n "Enter the number of dimes: "
		read dime
		echo -n "Enter the number of nickels: "
		read nickel
		echo -n "Enter the number of pennies: "
		read penny
		sumCoins $quarter $dime $nickel $penny
		echo "The total amount of money in the bag is $ans cents."
		;;
	6) 	
		echo -n "Enter the radius of the cylinder's base: "
		read cylBase
		baseArea=$(circleArea $cylBase)
		echo -n "Enter the height of the cylinder: "
		read cylHeight
		cylVol=$(cylinderVolume $baseArea $cylHeight)
		echo "The volume of the cylinder is $cylVol."
		;;
	*) echo "Oops, you did not select a valid option.";;
esac


