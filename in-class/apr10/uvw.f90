! Class Challenge #12: Fortran
! Jatin Khare
! UTEID: jk47976


program uvw

implicit none

integer :: a
integer :: b
integer :: c
integer :: m
integer :: n
real :: max_number
integer :: loop_v
a = 0
b = 0
c = 0
m = 2
n = 0
loop_v = 0
max_number = 10000
do while(loop_v<max_number)
        do n = 1,m
                a = m*m - n*n
                b = 2*m*n
                c = m*m + n*n
                if(c > sqrt(max_number)) then
                        EXIT
                end if
                if(a /= 0 .and. b /= 0) then
                        print "(a6, i2, a6, i2, a6, i3)", 'a = ',a, ', b = ',b,', c = ',c
                end if
        end do  
        m = m+1
        loop_v = c
end do   

end program uvw
