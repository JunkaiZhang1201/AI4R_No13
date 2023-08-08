# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ai4r_interfaces:msg/TemplateMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'temp_float64_array'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TemplateMessage(type):
    """Metaclass of message 'TemplateMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ai4r_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ai4r_interfaces.msg.TemplateMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__template_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__template_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__template_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__template_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__template_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TemplateMessage(metaclass=Metaclass_TemplateMessage):
    """Message class 'TemplateMessage'."""

    __slots__ = [
        '_temp_bool',
        '_temp_uint32',
        '_temp_int32',
        '_temp_float32',
        '_temp_float64',
        '_temp_string',
        '_temp_float64_array',
    ]

    _fields_and_field_types = {
        'temp_bool': 'boolean',
        'temp_uint32': 'uint32',
        'temp_int32': 'int32',
        'temp_float32': 'float',
        'temp_float64': 'double',
        'temp_string': 'string',
        'temp_float64_array': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.temp_bool = kwargs.get('temp_bool', bool())
        self.temp_uint32 = kwargs.get('temp_uint32', int())
        self.temp_int32 = kwargs.get('temp_int32', int())
        self.temp_float32 = kwargs.get('temp_float32', float())
        self.temp_float64 = kwargs.get('temp_float64', float())
        self.temp_string = kwargs.get('temp_string', str())
        self.temp_float64_array = array.array('d', kwargs.get('temp_float64_array', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.temp_bool != other.temp_bool:
            return False
        if self.temp_uint32 != other.temp_uint32:
            return False
        if self.temp_int32 != other.temp_int32:
            return False
        if self.temp_float32 != other.temp_float32:
            return False
        if self.temp_float64 != other.temp_float64:
            return False
        if self.temp_string != other.temp_string:
            return False
        if self.temp_float64_array != other.temp_float64_array:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def temp_bool(self):
        """Message field 'temp_bool'."""
        return self._temp_bool

    @temp_bool.setter
    def temp_bool(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'temp_bool' field must be of type 'bool'"
        self._temp_bool = value

    @builtins.property
    def temp_uint32(self):
        """Message field 'temp_uint32'."""
        return self._temp_uint32

    @temp_uint32.setter
    def temp_uint32(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'temp_uint32' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'temp_uint32' field must be an unsigned integer in [0, 4294967295]"
        self._temp_uint32 = value

    @builtins.property
    def temp_int32(self):
        """Message field 'temp_int32'."""
        return self._temp_int32

    @temp_int32.setter
    def temp_int32(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'temp_int32' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'temp_int32' field must be an integer in [-2147483648, 2147483647]"
        self._temp_int32 = value

    @builtins.property
    def temp_float32(self):
        """Message field 'temp_float32'."""
        return self._temp_float32

    @temp_float32.setter
    def temp_float32(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temp_float32' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'temp_float32' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._temp_float32 = value

    @builtins.property
    def temp_float64(self):
        """Message field 'temp_float64'."""
        return self._temp_float64

    @temp_float64.setter
    def temp_float64(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temp_float64' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'temp_float64' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._temp_float64 = value

    @builtins.property
    def temp_string(self):
        """Message field 'temp_string'."""
        return self._temp_string

    @temp_string.setter
    def temp_string(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'temp_string' field must be of type 'str'"
        self._temp_string = value

    @builtins.property
    def temp_float64_array(self):
        """Message field 'temp_float64_array'."""
        return self._temp_float64_array

    @temp_float64_array.setter
    def temp_float64_array(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'temp_float64_array' array.array() must have the type code of 'd'"
            self._temp_float64_array = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'temp_float64_array' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._temp_float64_array = array.array('d', value)
