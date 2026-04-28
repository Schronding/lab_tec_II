from ij import IJ

# Process images
for i in range(1, 9):
    source_path = "C:/Users/Storm trooper/Desktop/originales_golgi/golgi_cox_4x_mosaico_%d.tiff" % i
    IJ.open(source_path)
    IJ.run("Subtract Background...", "rolling=50")
    IJ.run("Unsharp Mask...", "radius=1 mask=0.60")
    dest_path = "C:/Users/Storm trooper/Desktop/proceso_golgi/golgi_cox_4x_mosaico_%d_back_unsharp.tif" % i
    IJ.saveAs("Tiff", dest_path)
    IJ.getImage().close()

