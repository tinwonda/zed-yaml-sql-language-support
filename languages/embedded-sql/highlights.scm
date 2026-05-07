(identifier) @variable

(object_reference
  (identifier) @type)

(relation
  (identifier) @type)

(cte
  (identifier) @type)

(invocation
  (object_reference
    name: (identifier) @function.call))

(field
  name: (identifier) @field)

(column_definition
  name: (identifier) @field)

(column
  name: (identifier) @field)

(term
  alias: (identifier) @variable)

(literal) @string
(comment) @comment
(marginalia) @comment

((literal) @number
  (#match? @number "^[-+]?%d+$"))

((literal) @float
  (#match? @float "^[-+]?%d*\\.%d*$"))

(parameter) @variable.parameter

[
  (keyword_true)
  (keyword_false)
] @boolean

(keyword_null) @constant.builtin

[
  (keyword_select)
  (keyword_from)
  (keyword_where)
  (keyword_insert)
  (keyword_into)
  (keyword_values)
  (keyword_update)
  (keyword_set)
  (keyword_delete)
  (keyword_create)
  (keyword_alter)
  (keyword_drop)
  (keyword_table)
  (keyword_view)
  (keyword_index)
  (keyword_join)
  (keyword_left)
  (keyword_right)
  (keyword_inner)
  (keyword_outer)
  (keyword_full)
  (keyword_cross)
  (keyword_group)
  (keyword_order)
  (keyword_by)
  (keyword_having)
  (keyword_limit)
  (keyword_offset)
  (keyword_distinct)
  (keyword_as)
  (keyword_case)
  (keyword_when)
  (keyword_then)
  (keyword_else)
  (keyword_end)
  (keyword_begin)
  (keyword_commit)
  (keyword_rollback)
  (keyword_returning)
  (keyword_union)
  (keyword_except)
  (keyword_intersect)
  (keyword_exists)
  (keyword_between)
  (keyword_like)
  (keyword_similar)
  (keyword_over)
  (keyword_partition)
  (keyword_window)
  (keyword_with)
  (keyword_recursive)
] @keyword

[
  (keyword_in)
  (keyword_and)
  (keyword_or)
  (keyword_not)
  (keyword_on)
  (keyword_is)
] @keyword.operator

[
  (keyword_int)
  (keyword_smallint)
  (keyword_bigint)
  (keyword_decimal)
  (keyword_numeric)
  (keyword_float)
  (keyword_double)
  (keyword_real)
  (keyword_boolean)
  (keyword_char)
  (keyword_varchar)
  (keyword_text)
  (keyword_uuid)
  (keyword_json)
  (keyword_jsonb)
  (keyword_date)
  (keyword_time)
  (keyword_datetime)
  (keyword_timestamp)
  (keyword_timestamptz)
  (keyword_interval)
] @type.builtin

[
  "+"
  "-"
  "*"
  "/"
  "%"
  "^"
  ":="
  "="
  "<"
  "<="
  "!="
  ">="
  ">"
  "<>"
  (op_other)
  (op_unary_other)
] @operator

[
  "("
  ")"
] @punctuation.bracket

[
  ";"
  ","
  "."
] @punctuation.delimiter
