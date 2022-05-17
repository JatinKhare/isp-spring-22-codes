! In-class Challenge #14: Identity Matrix
! Jatin Khare
! UTEID: jk47976

program i_matrix
implicit none

integer, parameter :: n = 100
integer, dimension(n,n) :: r, r_filled, r_print
r_filled = fill_matrix(n,r)
r_print = print_matrix(n,r)

contains

integer function fill_matrix(n, r_loc)
implicit none
integer :: n, i,j
integer, dimension(n,n) :: r_loc

do i = 1,n
        do j = 1,n
                if(i .eq. j) then
                        r_loc(i,j) = 1
                else
                        r_loc(i,j) = 0
                end if
        end do
end do
end function

integer function print_matrix(n, r_loc)
implicit none
integer :: n, i,j,k,l
integer, dimension(n,n) :: r_loc

do k=1, n
        write(*,100) (r_loc(k,l),l=1,n)
end do
100 format(100(1x,i2))
stop

end function

end program i_matrix
