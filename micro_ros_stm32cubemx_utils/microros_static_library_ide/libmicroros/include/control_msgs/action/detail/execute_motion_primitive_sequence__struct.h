// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_msgs:action/ExecuteMotionPrimitiveSequence.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__ACTION__DETAIL__EXECUTE_MOTION_PRIMITIVE_SEQUENCE__STRUCT_H_
#define CONTROL_MSGS__ACTION__DETAIL__EXECUTE_MOTION_PRIMITIVE_SEQUENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "control_msgs/msg/detail/motion_primitive_sequence__struct.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_Goal
{
  control_msgs__msg__MotionPrimitiveSequence trajectory;
} control_msgs__action__ExecuteMotionPrimitiveSequence_Goal;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_Goal.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_Goal__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_Goal__Sequence;


// Constants defined in the message

/// Constant 'SUCCESSFUL'.
enum
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_Result__SUCCESSFUL = 0l
};

/// Constant 'INVALID_GOAL'.
enum
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_Result__INVALID_GOAL = -1l
};

/// Constant 'OLD_HEADER_TIMESTAMP'.
enum
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_Result__OLD_HEADER_TIMESTAMP = -3l
};

// Include directives for member types
// Member 'error_string'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_Result
{
  int32_t error_code;
  rosidl_runtime_c__String error_string;
} control_msgs__action__ExecuteMotionPrimitiveSequence_Result;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_Result.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_Result__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback
{
  uint8_t current_primitive_index;
} control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "control_msgs/action/detail/execute_motion_primitive_sequence__struct.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  control_msgs__action__ExecuteMotionPrimitiveSequence_Goal goal;
} control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Request;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Request.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Request__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Response;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Response.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Response__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Request;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Request.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Request__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "control_msgs/action/detail/execute_motion_primitive_sequence__struct.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Response
{
  int8_t status;
  control_msgs__action__ExecuteMotionPrimitiveSequence_Result result;
} control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Response;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Response.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Response__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "control_msgs/action/detail/execute_motion_primitive_sequence__struct.h"

/// Struct defined in action/ExecuteMotionPrimitiveSequence in the package control_msgs.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  control_msgs__action__ExecuteMotionPrimitiveSequence_Feedback feedback;
} control_msgs__action__ExecuteMotionPrimitiveSequence_FeedbackMessage;

// Struct for a sequence of control_msgs__action__ExecuteMotionPrimitiveSequence_FeedbackMessage.
typedef struct control_msgs__action__ExecuteMotionPrimitiveSequence_FeedbackMessage__Sequence
{
  control_msgs__action__ExecuteMotionPrimitiveSequence_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__action__ExecuteMotionPrimitiveSequence_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_MSGS__ACTION__DETAIL__EXECUTE_MOTION_PRIMITIVE_SEQUENCE__STRUCT_H_
