import matplotlib.pyplot as plt


dims = [
    2,
    4,
    8,
    16,
    32,
    64,
    128,
    256,
]

t_matmult = [
    0.000018,
    0.000051,
    0.000342,
    0.002218,
    0.018694,
    0.176169,
    1.625773,
    15.646681,
]

t_matmult_cache = [
    0.000030,
    0.000052,
    0.000168,
    0.000837,
    0.004913,
    0.034019,
    0.348234,
    2.442757,
]

t_opencv = [
    0.000182,
    0.000199,
    0.000360,
    0.001306,
    0.009087,
    0.069120,
    0.588789,
    4.806176,
]

t_eigen = [
    0.000027,
    0.000035,
    0.000109,
    0.000374,
    0.002332,
    0.017305,
    0.128563,
    1.081561,
]

plt.figure()
plt.plot(dims[:4], t_matmult[:4], label='matmult', marker='o')
plt.plot(dims[:4], t_matmult_cache[:4], label='matmult_cache (my impl.)', marker='o')
plt.plot(dims[:4], t_opencv[:4], label='opencv', marker='o')
plt.plot(dims[:4], t_eigen[:4], label='eigen', marker='o')
plt.legend()
plt.xlabel('Dimension')
plt.ylabel('Time (ms)')
plt.title('Matrix multiplication')
plt.grid()
plt.savefig('plot1.png')
plt.show()
plt.close()

plt.figure()
plt.plot(dims, t_matmult, label='matmult', marker='o')
plt.plot(dims, t_matmult_cache, label='matmult_cache (my impl.)', marker='o')
plt.plot(dims, t_opencv, label='opencv', marker='o')
plt.plot(dims, t_eigen, label='eigen', marker='o')
plt.legend()
plt.xlabel('Dimension')
plt.ylabel('Time (ms)')
plt.title('Matrix multiplication')
plt.grid()
plt.savefig('plot2.png')
plt.show()
plt.close()
