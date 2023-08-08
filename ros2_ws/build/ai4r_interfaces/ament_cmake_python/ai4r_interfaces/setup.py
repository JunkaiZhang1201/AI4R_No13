from setuptools import find_packages
from setuptools import setup

setup(
    name='ai4r_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('ai4r_interfaces', 'ai4r_interfaces.*')),
)
