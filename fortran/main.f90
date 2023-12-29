program matress
  implicit none

  character(len=100) :: filename
  integer :: size
  real, allocatable :: matrix(:,:)

  ! Get the filename from the command-line argument
  call get_command_argument(1, filename)

  call readSize(filename, size)

  ! Allocate the matrix
  allocate(matrix(size, size))

  ! Read the matrix values
  call readMatrix(filename, matrix, size)

  ! Print the matrix
  call printMatrix(size, matrix)

  ! Calculate and print the determinant
  write(*, *) 'Matrix determinant:', calculateDeterminant(size, matrix)

  ! Deallocate the matrix
  deallocate(matrix)

contains

  subroutine printMatrix(size, matrix)
    integer, intent(in) :: size
    real, intent(in) :: matrix(:,:)
    integer :: i, j  ! loop indices

    ! Print the matrix size and values (optional)
    write(*, *) 'Matrix size:', size
    write(*, *) 'Matrix values:'
    do i = 1, size
      write(*, '(1000(F6.3, 2X))') (matrix(i, j), j = 1, size)
    end do
  end subroutine printMatrix

  subroutine readMatrix(filename, matrix, size)
    character(len=*), intent(in) :: filename
    real, intent(out) :: matrix(:,:)
    integer, intent(in) :: size
    integer :: i, j
    integer :: ierr

    ! Open the file
    open(unit=10, file=trim(filename), status='old', action='read', iostat=ierr)

    ! Check if the file opened successfully
    if (ierr /= 0) then
      write(*, *) 'File didn''t open successfully: "', trim(filename), '"'
      return
    end if

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

  real function calculateDeterminant(size, matrix)
    integer, intent(in) :: size
    real, intent(in) :: matrix(size, size)
    real, dimension(size, size) :: LU
    integer :: i, j, k
    real :: det

    ! Initialize determinant
    det = 1.0

    ! Perform LU decomposition
    LU = matrix
    call LU_decomposition(size, LU)

    ! Calculate determinant as the product of diagonal elements of U
    do i = 1, size
      det = det * LU(i, i)
    end do

    calculateDeterminant = det
  end function calculateDeterminant

  subroutine LU_decomposition(size, A)
    integer, intent(in) :: size
    real, intent(inout) :: A(size, size)
    integer :: i, j, k
    real :: factor

    do k = 1, size - 1
      do i = k + 1, size
        factor = A(i, k) / A(k, k)
        A(i, k) = factor
        do j = k + 1, size
          A(i, j) = A(i, j) - factor * A(k, j)
        end do
      end do
    end do
  end subroutine LU_decomposition

end program matress
