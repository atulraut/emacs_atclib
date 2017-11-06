# emacs_atclib
atclib's emacs with full IDE feature enabled

# Install below packages 
sudo apt-get install emacs23 cscope cscope-el

# Configuration: We need to configure emacs to load cscope support, edit your ~/.emacs or ~/.emacs.d/init.el to include following line.
(require 'xcscope)

# If didnt work : check your xcscxope.el path
(load-file "/usr/share/emacs/site-lisp/xcscope.el")
(require 'xcscope)

# Used attach cscope script and run on your project : Assume script.cscope kept at directory ~/bin/
~/bin/script.cscope

# Build ctags
cscope -b

# Use ctgags or can used with EMACS             
cscope -d 

# Ref :
https://techtooltip.wordpress.com/2012/01/06/how-to-integrate-emacs-cscope-to-browse-linux-kernel-source-code/ 
