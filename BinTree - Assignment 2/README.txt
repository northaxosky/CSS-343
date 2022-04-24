// CONCERNING int getHeight() //
the getHeight function is not const because I streamlined it using retrieve which is not const.
This allows me to not create another helper function for getHeight and lets me reuse my retrieve function.