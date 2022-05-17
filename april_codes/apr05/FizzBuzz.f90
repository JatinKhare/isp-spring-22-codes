! Class Challenge #11: Fortran
! Jatin Khare
! UTEID: jk47976


program fizzbuzz

implicit none

! Declaring the variables
integer :: input;
integer :: case_v

!Taking input from the user

!print *, "Enter a number.."
!read *, input

!Hard coding it to a value 15
print *, "Hardcoding the number to 15 for submission"
input = 15

!With mod Checking if it is a multiple of 3, 5, or 15
if(mod(input,3) == 0 .and. mod(input,5) /=0) then
        case_v = 0
else if(mod(input,3) /= 0 .and. mod(input,5) ==0) then
        case_v = 1
else if(mod(input,15)==0) then
        case_v = 2
end if

!Print according to the case statement
select case(case_v)

        case(0)
                print *, "Fizz (with mod)"

        case (1)
                print *, "Buzz (with mod)"

        case(2)
                print *, "FizzBuzz (with mod)"
end select

!Without mod Checking if it is a multiple of 3, 5, or 15
if(((input/3) - input) == 0 .and. ((input/5) - input)/=0) then
        case_v = 0
else if(((input/3) - input) /=0 .and. ((input/5) - input) ==0) then
        case_v = 1
else if(((input/15) - input) == 0) then
        case_v = 2
end if

!Print according to the case statement
select case(case_v)

        case(0)
                print *, "Fizz (without mod)"

        case (1)
                print *, "Buzz (without mod)"

        case(2)
                print *, "FizzBuzz (without mod)"
end select
end program fizzbuzz
