! Homework #7: Fortran Collatz Conjecture
! Jatin Khare
! UTEID: jk47976

program collatz_n
implicit none

integer::number, n, iter, that_number, max_iter
number = 2
n = 0
max_iter = 0
that_number = 0
! A while loop for going through all the numbers
do while(number<1000)
        n = number
        iter = 0
        do while(n/=1)
                if(mod(n,2)==0) then
                        n = even_collatz(n) !if the number is even
                else
                        n = odd_collatz(n)  !if the number is odd
                end if
        iter = iter+1;
        end do
if(iter>=max_iter) then  !keep looking for the max iteration
        max_iter = iter
        that_number = number
print "(a42, i3)", 'Number that took longest sequence (yet) = ', that_number
print "(a18, i3)", 'Sequence length = ', max_iter
print "(/)"
end if
number = number + 1
end do
contains

!next number in collatz conjecture for a even input
integer function even_collatz(a)
implicit none
integer :: a
 even_collatz = a/2
end function

!next number in collatz conjecture for a odd input
integer function odd_collatz(a)
implicit none
integer :: a
 odd_collatz = 3*a + 1
end function
end program collatz_n
