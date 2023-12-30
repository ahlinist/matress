module MatrixOperations
  implicit none

  public :: calculateDeterminant, decomposeMatrix

  contains

  real function calculateDeterminant(size, matrix)
    integer, intent(in) :: size
    real, intent(in) :: matrix(size, size)
    real, dimension(size, size) :: LU
    integer :: i, j, k
    real(8) :: det

    ! Initialize determinant
    det = 1.0

    ! Perform LU decomposition
    LU = matrix
    call decomposeMatrix(size, LU)

    ! Calculate determinant as the product of diagonal elements of U
    do i = 1, size
      det = det * LU(i, i)
    end do

    calculateDeterminant = det
  end function calculateDeterminant

  subroutine decomposeMatrix(size, matrix)
    integer, intent(in) :: size
    real, intent(inout) :: matrix(size, size)
    integer :: i, j, k
    real :: factor

    do k = 1, size - 1
      do i = k + 1, size
        factor = matrix(i, k) / matrix(k, k)
        do j = k, size
          matrix(i, j) = matrix(i, j) - factor * matrix(k, j)
        end do
      end do
    end do
  end subroutine decomposeMatrix

end module MatrixOperations
