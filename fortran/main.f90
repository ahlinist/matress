program matress
  implicit none

  character(len=100) :: filename
  integer :: size

  ! Get the filename from the command-line argument
  call get_command_argument(1, filename)

  call readSize(filename, size)

  ! Print the number of tokens
  write(*, *) 'matrix size:', size

contains

  subroutine readSize(filename, size)
    character(len=*), intent(in) :: filename
    character(len=1000) :: line
    integer :: ierr, i
    integer, intent(out) :: size

    ! Open the file
    open(unit=10, file=trim(filename), status='old', action='read', iostat=ierr)

    ! Check if the file opened successfully
    if (ierr /= 0) then
      write(*,*) 'Error opening file "', trim(filename), '"'
      stop
    end if

    ! Read the first line
    read(10, '(A)', iostat=ierr) line

    ! Count the number of tokens (assuming tokens are separated by commas)
    size = 1
    do i = 1, len_trim(line)
      if (line(i:i) == ',') then
          size = size + 1
      end if
    end do

    ! Close the file
    close(unit=10)
  end subroutine readSize

end program matress
