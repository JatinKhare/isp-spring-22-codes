! In-class Challenge #13: Random Array Sort
! Jatin Khare
! UTEID: jk47976

program array_sort
implicit none

integer, parameter :: n = 100
real, dimension(n) :: r
real, dimension(n) :: r_i
real, dimension(n) :: p
call random_number(r)
r_i = FLOOR(100*r)
print "(/)"
print *, 'Array before sorting..'
print "(/)"
print *, r_i

print "(/)"
print "(a32, i2)", 'Sorted status before sorting = ', check_sorted(n, r_i)
p = sort_array(n,r_i)
print "(/)"
print *, 'Array before sorting..'
print "(/)"
print *, r_i
print "(/)"
print "(a32, i2)", 'Sorted status after sorting = ', check_sorted(n, r_i)

contains

integer function sort_array(n, r)
implicit none
integer :: n, count_n
real, dimension(n) :: r
integer :: itr
real :: temp
count_n = 1
do while(count_n<n+1)
itr = 1

do while(itr<n)
        if(r(itr) > r(itr + 1)) then
                temp = r(itr)
                !print *, 'itr=',itr
                !print *, 'temp=',r(itr)
                r(itr) = r(itr + 1)
                r(itr + 1) = temp
        end if
itr = itr + 1
end do
count_n = count_n + 1
end do
end function

integer function check_sorted(n, r_c)
implicit none
integer :: n, flag = 1
real, dimension(n) :: r_c
integer :: itr
itr = 1
check_sorted = flag
!print *, 'value = ', flag
!print *, r_c
do while(itr<n)
        if(r_c(itr+1) - r_c(itr)<0) then
                !print *,'*itr = ', r_c(itr), '*irt+1', r_c(itr+1)
                !print *, 'temp=',r_c(itr)
                flag = 0
                EXIT
        end if
itr = itr + 1
end do
check_sorted = flag
flag = 1
!print *, 'value = ', check_sorted
end function

end program array_sort
