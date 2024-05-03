#!/bin/bash
#
# Inform the user
echo "Now starting the \"updatewebinterface.sh\" shell script"
echo ""
#
# Put the web home as a variable
wwwhome="/var/www/html"
#
# Put the asclinic home as a variable
asclinichome="/home/asc-share/asclinic-system/web_interface/html"
#
# Inform the user of the directories
echo "Using the following directories:"
echo ">> wwwhome = $wwwhome"
echo ">> asclinichome = $asclinichome"
echo ""
#
# Change directory to the web home
cd $wwwhome
echo "Changed directory to $wwwhome"
echo ""
#
#
#
# REMOVE the contents of the js folder
rm -v js/*.js
echo "Removed the \"*.js\" contents of the \"js\" folder"
rm -v js/*
echo "Removed any other contents of the \"js\" folder"
rmdir -v js
echo "Removed the \"js\" folder"
echo ""
#
# Make the js folder again
mkdir -v js
echo "Remade the \"js\" folder"
# Copy the javscripts files
cp -v $asclinichome"/js/"*.js $wwwhome"/js/"
echo "Copied across the \"js\" folder contents"
echo ""
#
#
#
# REMOVE the contents of the img folder
rm -v img/*.*
echo "Removed the \"*.*\" contents of the \"img\" folder"
rm -v img/*
echo "Removed any other contents of the \"img\" folder"
rmdir -v img
echo "Removed the \"img\" folder"
echo ""
#
# Make the img folder again
mkdir -v img
echo "Remade the \"img\" folder"
# Copy the img files
cp -v $asclinichome"/img/"*.* $wwwhome"/img/"
echo "Copied across the \"img\" folder contents"
echo ""
#
#
#
# REMOVE the contents of the css folder
rm -v css/*.css
echo "Removed the \"*.css\" contents of the \"css\" folder"
rm -v css/*
echo "Removed any other contents of the \"css\" folder"
rmdir -v css
echo "Removed the \"css\" folder"
echo ""
#
# Make the css folder again
mkdir -v css
echo "Remade the \"css\" folder"
# Copy the img files
cp -v $asclinichome"/css/"*.css $wwwhome"/css/"
echo "Copied across the \"css\" folder contents"
echo ""
#
#
#
# REMOVE the contents of the bashscripts folder
rm -v bashscripts/*.sh
echo "Removed all the contents of the \"bashscripts\" folder"
rmdir -v bashscripts
echo "Removed the \"bashscripts\" folder"
echo ""
#
# Make the bashscripts folder again
mkdir -v bashscripts
echo "Remade the \"bashscripts\" folder"
# Copy the bashscript files
cp -v $asclinichome"/bashscripts/"*.sh $wwwhome"/bashscripts/"
echo "Copied across the \"bashscripts\" folder contents"
echo ""
#
#
#
# Remove the "uploads" folder, if it exists
rm -v uploads/*
echo "Removed all contents of the \"uploads\" folder"
rmdir -v uploads
echo "Removed the \"uploads\" folder"
echo ""
#
# Make the uploads folder again
mkdir -v uploads
echo "Remade the \"uploads\" folder"
echo ""
#
#
#
# Remove the "outfiles_for_nodes" folder, if it exists
rm -v outfiles_for_nodes/*
echo "Removed all contents of the \"outfiles_for_nodes\" folder"
rmdir -v outfiles_for_nodes
echo "Removed the \"outfiles_for_nodes\" folder"
echo ""
#
# Make the "outfiles_for_nodes" folder again
mkdir -v outfiles_for_nodes
echo "Remade the \"outfiles_for_nodes\" folder"
echo ""
# Copy the outfiles "readme"
cp -v $asclinichome"/outfiles_for_nodes/"*.txt $wwwhome"/outfiles_for_nodes/"
echo "Copied across the \"outfiles_for_nodes\" folder contents"
echo ""
#
#
#
# REMOVE the contents of the wwwhome folder
rm -v *.php
rm -v *.html
rm -v *.*
echo "Removed all the contents of the \"wwwhome\" folder"
echo ""
#
# Copy the html files
cp -v $asclinichome"/"*.html $wwwhome"/"
echo "Copied across the \"*.html\" files"
echo ""
# Copy the php files
cp -v $asclinichome"/"*.php $wwwhome"/"
echo "Copied across the \"*.php\" files"
echo ""
#
#
#
# APPLY the agent namespace to the rosbridge JavaScript file
echo "Now substituting the default agent namespace into the ros bridge JavaScript"
# Copy across the bash script
cp -v $asclinichome"/js/"*.sh $wwwhome"/js/"
# Run the bash script
SCRIPT_PATH="/var/www/html/js/substitute_namespace_into_rosbridge_javascript.sh"
OUTPUT=$("$SCRIPT_PATH")
echo $OUTPUT
echo "Substitution script complete, see previous line for status."
echo ""
#
#
#
# Add write access for the group to all files
#chmod -R g+rw $wwwhome
