program matress
  use MatrixIO
  use MatrixOperations
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

  ! Calculate and print the determinant
  write(*, *) 'Matrix determinant:', calculateDeterminant(size, matrix)

  ! Deallocate the matrix
  deallocate(matrix)

end program matress
