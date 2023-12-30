module MatrixIO
  implicit none

  public :: readMatrix

  contains

  subroutine readMatrix(filename, matrix, size)
    character(len=*), intent(in) :: filename
    real, allocatable, intent(out) :: matrix(:,:)
    integer, intent(out) :: size
    character(len=100000000) :: line
    integer :: i, j
    integer :: ierr

    ! Open the file
    open(unit=10, file=trim(filename), status='old', action='read', iostat=ierr)

    ! Check if the file opened successfully
    if (ierr /= 0) then
      write(*, *) 'File didn''t open successfully: "', trim(filename), '"'
      return
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

    ! Open the file
    open(unit=10, file=trim(filename), status='old', action='read', iostat=ierr)

    ! Allocate the matrix
    allocate(matrix(size, size))

    ! Read the matrix values
    do i = 1, size
      read(10, *, iostat=ierr) (matrix(i, j), j = 1, size)
      if (ierr /= 0) then
        close(unit=10)
        return
      end if
    end do

    if (ierr /= 0) then
      write(*, *) 'Error reading matrix values from file "', trim(filename), '"'
      return
    end if

    ! Close the file
    close(unit=10)
  end subroutine readMatrix

end module MatrixIO
