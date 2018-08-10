
program main

implicit none

type mat_vars_t
   real, pointer :: eps_p_old (:)
   real          :: alpha_old
end type mat_vars_t

integer, parameter        :: N = 3
integer                   :: i, j
type(mat_vars_t), pointer :: int_vars_n (:)

allocate(int_vars_n(N))

do i = 1, N
    allocate(int_vars_n(i)%eps_p_old(6))
end do

! initialize
int_vars_n(1)%alpha_old = 1.0
do i = 1, 6
    int_vars_n(1)%eps_p_old(i) = 1.0
end do

int_vars_n(2)%alpha_old = 2.0
do i = 1, 6
    int_vars_n(2)%eps_p_old(i) = 2.0
end do

int_vars_n(3)%alpha_old = 3.0
do i = 1, 6
    int_vars_n(3)%eps_p_old(i) = 3.0
end do

do i = 1, N
write(*,"(A, I5, A, F10.2)", advance="no") "int_var = ", i, " alpha_old = ", int_vars_n(i)%alpha_old
write(*,"(A)", advance="no") "   eps_p_old = "
do j = 1, 6
    write(*,"(F10.2, A)", advance="no") int_vars_n(i)%eps_p_old(j), " "
end do
write(*,*)
end do


end program main
