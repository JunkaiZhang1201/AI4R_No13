from setuptools import find_packages
from setuptools import setup

setup(
    name='ai4r_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('ai4r_pkg', 'ai4r_pkg.*')),
)
