! Homework #8: Newton's Method
! 21 April, 2022
! Jatin Khare
! UTEID: jk47976

program newton
implicit none

real, parameter :: eps = 0.0001
integer, parameter :: max_iter = 100, arr_ind = 1001
real :: x, y
integer :: ans, i
real, dimension(arr_ind) :: x_array
real, dimension(arr_ind) :: root_array
integer, dimension(arr_ind) :: iter_array
x = 0
i = 1
do while (i <= 1001)
        !print *, "x_old= ", x_array(i)

        ans = converge_func(max_iter, eps, x, root_array, i)    !calling the
                                                                ! newton's function 
        x_array(i) = x
        iter_array(i) = ans
        i = i + 1
        x = x + 0.01
        !print *, "i= ", iter_array(i)
end do
ans = print_array_details(x_array, iter_array, root_array, arr_ind)
contains

!printing the arrays

integer function print_array_details(x_array, iter_array, root_array, arr_ind)
implicit none
integer :: arr_ind, i
real, dimension(arr_ind) :: x_array
real, dimension(arr_ind) :: root_array
integer, dimension(arr_ind) :: iter_array

do i = 1, arr_ind
write(*, 20, advance = 'no') x_array(i)
!write(*, 40, advance = 'no') root_array(i)
write(*, 30) iter_array(i)
end do
20 format("x = ",f5.2)
!40 format(",   converged at = ",f10.7)
30 format(",   iterations to converge = ", i3)
end function

real function f(x)
implicit none
real :: x

f = x**3        !the function

end function

real function p(x)
implicit none
real :: x

p = 3*x**2      !the derivative of the function

end function

real function x_new(x_old)
implicit none
real :: x_old
x_new = x_old - f(x_old)/p(x_old)
end function

integer function converge_func(max_iter, eps, x, root_array, i)
implicit none
integer :: max_iter
real :: x, x_old, eps
real, dimension(1001) :: root_array
integer :: count_iter, k, i
real :: x_n_1 
count_iter = 0
x_old = x
do k=1, max_iter
        if(x==0) then
                count_iter = 100        !as per Slack
                EXIT
        end if 
        x_n_1 = x_new(x_old)            !updating the x
        if(abs((x_old - x_n_1)) .le. eps) then  !condition to break iterations
        !print *, "converge successful at ", x_n_1
        root_array(i) = x_n_1
        EXIT
        end if
        count_iter = count_iter + 1
        x_old = x_n_1
end do
converge_func = count_iter
count_iter = 0          !re-initializing count

end function

end program newton
