
from bemio.io import wamit as wio
from bemio.data import bem as hd
import matplotlib.pyplot as plt
plt.close('all')
plt.interactive(True)

# Load the data
w = wio.WamitOutput(outFile='rm3.out')

# Calculate IRF and plot
for i in xrange(2):
	w.data[i].calcIRF(n_t = 10000)
	w.data[i].plotIRF([[0,0],[2,2]]	)
	w.data[i].plotAddedMassAndDamping([[0,0],[2,2]])

# Save the data in HDF5 format
hd.writeHdf5(w.data,w.files['hdf5'])
