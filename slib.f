      SUBROUTINE KAPPASIGMA(D,S,M,N,O,ITER,KAPPA)
C
      INTEGER M, N, O, ITER
      INTEGER, DIMENSION(M,N,O) :: D
      INTEGER, DIMENSION(M,N) :: S
      INTEGER, DIMENSION(O) :: AUX1D1
      REAL, DIMENSION(O) :: AUX1D2
      REAL :: MEAN, SIGMA, KAPPA
CF2PY INTENT(OUT) :: S
CF2PY INTENT(HIDE) :: N
CF2PY INTENT(HIDE) :: M
CF2PY INTENT(HIDE) :: O
      DO 100 IT = 1,ITER
          DO 20 I = 1,M
             DO 40 J=1,N
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
 40         CONTINUE
 20     CONTINUE
100   CONTINUE
          DO 200 I = 1,M
             DO 400 J=1,N
                S(I,J) = SUM(D(I,J,:))/O
400         CONTINUE
200     CONTINUE
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
      DO 20 I = 1,M
         DO 40 J=1,N
            DO 60 K=1,O
               INPUT(I,J,K) = INPUT(I,J,K) * WEIGHT(K)/WEIGHTMEAN
C        y = np.where(x < mean - (sigma*kappa),mean,x)
C        sqrt(((x - mean)**2).mean()).mean()
C     $          0
 60         CONTINUE       
         OUTPUT(I,J) = NINT(SUM(INPUT(I,J,:))/O)
 40      CONTINUE
 20   CONTINUE
      END
