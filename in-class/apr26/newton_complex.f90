! Mid-term project: Newton's Method with Complex Numbers
! 26 April, 2022
! Jatin Khare
! UTEID: jk47976

program newton
implicit none

real, parameter :: eps = 0.0001
integer, parameter :: max_iter = 100, arr_ind = 400
complex :: ans, x, y
integer :: i, j
real :: a, b
complex, dimension(arr_ind) :: x_array
complex, dimension(arr_ind, arr_ind) :: root_array
integer, dimension(arr_ind, arr_ind) :: iter_array
b = -2
i = 1
j = 1
do while (i <= arr_ind)
        a = -2
        j = 1
        !print *, "x_old= ", x_array(i)
        do while(j<= arr_ind)
                x = cmplx(a,b)
                ans = converge_func(max_iter, eps, x, root_array, i, j, arr_ind)    !calling the
                                                                        ! newton's function 
                x_array(i) = x
                iter_array(i, j) = ans
                a = a + 0.01
                !print *, "i= ", i, "j= ", j
                j = j + 1 
        end do
        b = b + 0.01
        i = i + 1
end do
open (unit  = 7, file = "a_data.txt")
open (unit  = 8, file = "b_data.txt")
open (unit  = 9, file = "iteration_data.txt")
i = 1
j = 1

do while(i <= arr_ind)
        j = 1
        do while (j<=arr_ind)
                write (7, *) real(root_array(i,j))
                write (8, *) aimag(root_array(i,j))
                write (9, '(I4,X)', advance = 'no') (iter_array(i,j))
        j = j + 1 
        end do
                write (9, *)''
i = i + 1
end do 
!ans = print_array_details(x_array, iter_array, root_array, arr_ind)
contains

!printing the arrays

integer function print_array_details(x_array, iter_array, root_array, arr_ind)
implicit none
integer :: arr_ind, i
complex, dimension(arr_ind) :: x_array
complex, dimension(arr_ind) :: root_array
integer, dimension(arr_ind) :: iter_array

do i = 1, arr_ind
write(*, 20, advance = 'no') real(x_array(i))
!write(*, 40, advance = 'no') root_array(i)
write(*, 30) iter_array(i)
end do
20 format("x = ",f5.2)
!40 format(",   converged at = ",f10.7)
30 format(",   iterations to converge = ", i3)
end function

complex function f(x)
implicit none
complex :: x

f = log(x) + 2.71**x 
f =  3*x**4 - 1/x        !the function

end function

complex function p(x)
implicit none
complex :: x

p = 12*x**3 + 1/x**2      !the derivative of the function
end function

complex function x_new(x_old)
implicit none
complex :: x_old
x_new = x_old - f(x_old)/p(x_old)
end function

integer function converge_func(max_iter, eps, x, root_array, i, j, arr_ind)
implicit none
integer :: max_iter, arr_ind
complex :: x, x_old
real ::  eps
complex, dimension(arr_ind ,arr_ind) :: root_array
integer :: count_iter, k, i, j
complex :: x_n_1 
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
        root_array(i,j) = x_n_1
        EXIT
        end if
        count_iter = count_iter + 1
        x_old = x_n_1
end do
converge_func = count_iter
count_iter = 0          !re-initializing count

end function

end program newton
