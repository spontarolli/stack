      SUBROUTINE KAPPASIGMA(D,S,M,N,O,ITER,KAPPA)
C
      INTEGER M, N, O, ITER
<<<<<<< HEAD
      INTEGER*2, DIMENSION(M,N,O) :: D
      INTEGER*2, DIMENSION(M,N) :: S
      INTEGER*2, DIMENSION(O) :: AUX1D1
=======
>>>>>>> 38a6592f15a77caac367ae0d3e257d2b595241c8
      REAL, DIMENSION(O) :: AUX1D2
      REAL :: MEAN, SIGMA, KAPPA
CF2PY INTENT(OUT) :: S
CF2PY INTENT(HIDE) :: N
CF2PY INTENT(HIDE) :: M
CF2PY INTENT(HIDE) :: O
<<<<<<< HEAD
      DO IT = 1,ITER
          DO I = 1,M
             DO J=1,N
=======
>>>>>>> 38a6592f15a77caac367ae0d3e257d2b595241c8
                AUX1D1 = D(I,J,:)          
                MEAN = SUM(AUX1D1)/O
                AUX1D2 = (AUX1D1 - MEAN)**2
                SIGMA = SQRT(SUM(AUX1D2)/O)
                WHERE (AUX1D1 > (MEAN + SIGMA*KAPPA))
                    AUX1D1 = NINT(MEAN)
                END WHERE
                WHERE (AUX1D1 < (MEAN - SIGMA*KAPPA))
                    AUX1D1 = NINT(MEAN)
                END WHERE
                D(I,J,:) = AUX1D1
C            y = np.where(x < mean - (sigma*kappa),mean,x)
C            sqrt(((x - mean)**2).mean()).mean()
C     $          0
<<<<<<< HEAD
          END DO
        END DO
      END DO
          DO I = 1,M
             DO J=1,N
                S(I,J) = SUM(D(I,J,:))/O
             END DO
          END DO
=======
>>>>>>> 38a6592f15a77caac367ae0d3e257d2b595241c8
      END


      SUBROUTINE WEIGHTED_MEAN(INPUT,WEIGHT,OUTPUT,M,N,O)
C
      INTEGER M, N, O
      REAL, DIMENSION(M,N,O) :: INPUT
      INTEGER, DIMENSION(M,N) :: OUTPUT
      REAL, DIMENSION(O) :: WEIGHT
      REAL :: WEIGHTMEAN
CF2PY INTENT(OUT) :: OUTPUT
CF2PY INTENT(HIDE) :: N
CF2PY INTENT(HIDE) :: M
CF2PY INTENT(HIDE) :: O
      WEIGHTMEAN = SUM(WEIGHT)/O
<<<<<<< HEAD
      DO I = 1,M
         DO J=1,N
            DO K=1,O
=======
>>>>>>> 38a6592f15a77caac367ae0d3e257d2b595241c8
               INPUT(I,J,K) = INPUT(I,J,K) * WEIGHT(K)/WEIGHTMEAN
C        y = np.where(x < mean - (sigma*kappa),mean,x)
C        sqrt(((x - mean)**2).mean()).mean()
C     $          0
<<<<<<< HEAD
            END DO       
         OUTPUT(I,J) = NINT(SUM(INPUT(I,J,:))/O)
         END DO
       END DO
=======
>>>>>>> 38a6592f15a77caac367ae0d3e257d2b595241c8
      END
