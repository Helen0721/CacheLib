<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

type StructWithWrapper = \MyStructWrapper<\thrift_adapted_types\StructWithWrapper>;
/**
 * Original thrift enum:-
 * MyEnum
 */
enum MyEnum: int {
  UNKNOWN = 0;
  ONE = 1;
}

class MyEnum_TEnumStaticMetadata implements \IThriftEnumStaticMetadata {
  public static function getEnumMetadata()[]: \tmeta_ThriftEnum {
    return tmeta_ThriftEnum::fromShape(
      shape(
        "name" => "annotations.MyEnum",
        "elements" => dict[
          0 => "UNKNOWN",
          1 => "ONE",
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TEnumAnnotations {
    $structured_annotation_recursive0 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive0->name = "abc_enum";

    $structured_annotation_recursive1 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive1->name = "cba_enum";

    $structured_annotation_recursive0->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive1);

    $structured_annotation_recursive0->default = structured_annotation_with_default::fromShape(
      shape(
        "count" => 3,
      )
    );

    $structured_annotation_recursive2 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive2->name = "key_enum1";

    $structured_annotation_recursive3 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive3->name = "def_enum";

    $structured_annotation_recursive2->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive3);

    $structured_annotation_recursive4 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive4->name = "key_enum2";

    $structured_annotation_recursive5 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive5->name = "fed_enum";

    $structured_annotation_recursive4->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive5);

    $structured_annotation_recursive0->recurse_map = dict[
      "key_enum1" => $structured_annotation_recursive2,
      "key_enum2" => $structured_annotation_recursive4,
    ];

    return shape(
      'enum' => dict[],
      'constants' => dict[
        'UNKNOWN' => dict[
          'structured_annotation_recursive' => $structured_annotation_recursive0,
        ],
      ],
    );
  }
}

type i64WithWrapper = \MyTypeIntWrapper<\thrift_adapted_types\i64WithWrapper>;
/**
 * Original thrift struct:-
 * structured_annotation_with_default
 */
class structured_annotation_with_default implements \IThriftSyncStruct, \IThriftStructMetadata, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
    1 => shape(
      'var' => 'count',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'count' => 1,
  ];

  const type TConstructorShape = shape(
    ?'count' => ?int,
  );

  const type TShape = shape(
    'count' => int,
  );
  const int STRUCTURAL_ID = 1502749363246025945;
  /**
   * Original thrift field:-
   * 1: i32 count
   */
  public int $count;

  public function __construct(?int $count = null)[] {
    $this->count = $count ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'count'),
    );
  }

  public static function fromMap_DEPRECATED(@KeyedContainer<string, mixed> $map)[]: this {
    return new static(
      HH\FIXME\UNSAFE_CAST<mixed, int>(idx($map, 'count'), 'map value is mixed'),
    );
  }

  public function getName()[]: string {
    return 'structured_annotation_with_default';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "annotations.structured_annotation_with_default",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "count",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(dict<arraykey, T> $m)[]: dict<string, T> {
    return Dict\map_keys($m, $key ==> (string)$key);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
      $shape['count'],
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
      'count' => $this->count,
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'count') !== null) {
      $_tmp0 = (int)HH\FIXME\UNSAFE_CAST<mixed, int>($parsed['count']);
      if ($_tmp0 > 0x7fffffff) {
        throw new \TProtocolException("number exceeds limit in field");
      } else {
        $this->count = (int)$_tmp0;
      }
    }
  }

}

/**
 * Original thrift struct:-
 * structured_annotation_recursive
 */
class structured_annotation_recursive implements \IThriftAsyncStruct, \IThriftStructMetadata, \IThriftShapishAsyncStruct {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
    1 => shape(
      'var' => 'name',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'recurse',
      'is_wrapped' => true,
      'type' => \TType::STRUCT,
      'class' => structured_annotation_recursive::class,
    ),
    3 => shape(
      'var' => 'default',
      'type' => \TType::STRUCT,
      'class' => structured_annotation_with_default::class,
    ),
    4 => shape(
      'var' => 'recurse_map',
      'type' => \TType::MAP,
      'ktype' => \TType::STRING,
      'vtype' => \TType::STRUCT,
      'key' => shape(
        'type' => \TType::STRING,
      ),
      'val' => shape(
        'type' => \TType::STRUCT,
        'class' => structured_annotation_recursive::class,
      ),
      'format' => 'harray',
    ),
    5 => shape(
      'var' => 'int_field',
      'is_type_wrapped' => true,
      'type' => \TType::I64,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'name' => 1,
    'recurse' => 2,
    'default' => 3,
    'recurse_map' => 4,
    'int_field' => 5,
  ];

  const type TConstructorShape = shape(
    ?'name' => ?string,
    ?'recurse' => ?structured_annotation_recursive,
    ?'default' => ?structured_annotation_with_default,
    ?'recurse_map' => ?dict<string, structured_annotation_recursive>,
    ?'int_field' => ?\thrift_adapted_types\i64WithWrapper,
  );

  const type TShape = shape(
    'name' => string,
    ?'recurse' => ?structured_annotation_recursive::TShape,
    ?'default' => ?structured_annotation_with_default::TShape,
    'recurse_map' => dict<arraykey, structured_annotation_recursive::TShape>,
    'int_field' => \thrift_adapted_types\i64WithWrapper,
  );
  const int STRUCTURAL_ID = 3145177041506723998;
  /**
   * Original thrift field:-
   * 1: string name
   */
  public string $name;
  /**
   * Original thrift field:-
   * 2: annotations.structured_annotation_recursive recurse
   */
  private ?MyFieldWrapper<?structured_annotation_recursive, structured_annotation_recursive> $recurse;

  public function get_recurse()[]: MyFieldWrapper<?structured_annotation_recursive, structured_annotation_recursive> {
    return $this->recurse as nonnull;
  }

  /**
   * Original thrift field:-
   * 3: annotations.structured_annotation_with_default default
   */
  public ?structured_annotation_with_default $default;
  /**
   * Original thrift field:-
   * 4: map<string, annotations.structured_annotation_recursive> recurse_map
   */
  public dict<string, structured_annotation_recursive> $recurse_map;
  /**
   * Original thrift field:-
   * 5: annotations.i64WithWrapper int_field
   */
  public i64WithWrapper $int_field;

  public function set_int_field_DO_NOT_USE_THRIFT_INTERNAL(int $int_field)[write_props]: void {
    $this->int_field = \MyTypeIntWrapper::fromThrift_DO_NOT_USE_THRIFT_INTERNAL<\thrift_adapted_types\i64WithWrapper>($int_field);
  }


  public function __construct()[] {
    $this->name = '';
    $this->recurse_map = dict[];
    $this->int_field = \MyTypeIntWrapper::fromThrift_DO_NOT_USE_THRIFT_INTERNAL<\thrift_adapted_types\i64WithWrapper>(0);
    $this->recurse = MyFieldWrapper::fromThrift_DO_NOT_USE_THRIFT_INTERNAL<?structured_annotation_recursive, structured_annotation_recursive>(null, 2, $this);
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static async function genFromShape(self::TConstructorShape $shape)[zoned_shallow]: Awaitable<this> {
    $obj = new static();
    $name = Shapes::idx($shape, 'name');
    if ($name !== null) {
      $obj->name = $name;
    }
    $recurse = Shapes::idx($shape, 'recurse');
    if ($recurse !== null) {
      await $obj->get_recurse()->genWrap($recurse);
    }
    $default = Shapes::idx($shape, 'default');
    if ($default !== null) {
      $obj->default = $default;
    }
    $recurse_map = Shapes::idx($shape, 'recurse_map');
    if ($recurse_map !== null) {
      $obj->recurse_map = $recurse_map;
    }
    $int_field = Shapes::idx($shape, 'int_field');
    if ($int_field !== null) {
      $obj->int_field = await \MyTypeIntWrapper::genFromThrift<\thrift_adapted_types\i64WithWrapper>($int_field);
    }
    return $obj;
  }

  public static async function genFromMap_DEPRECATED(@KeyedContainer<string, mixed> $map): Awaitable<this> {
    $obj = new static();
    $name = idx($map, 'name');
    if ($name !== null) {
      $obj->name = HH\FIXME\UNSAFE_CAST<mixed, string>($name, 'Map value is mixed');
    }
    $recurse = idx($map, 'recurse');
    if ($recurse !== null) {
      await $obj->get_recurse()->genWrap(HH\FIXME\UNSAFE_CAST<mixed, structured_annotation_recursive>($recurse, 'Map value is mixed'));
    }
    $default = idx($map, 'default');
    if ($default !== null) {
      $obj->default = HH\FIXME\UNSAFE_CAST<mixed, structured_annotation_with_default>($default, 'Map value is mixed');
    }
    $recurse_map = idx($map, 'recurse_map');
    if ($recurse_map !== null) {
      $obj->recurse_map = HH\FIXME\UNSAFE_CAST<mixed, dict<string, structured_annotation_recursive>>($recurse_map, 'Map value is mixed');
    }
    $int_field = idx($map, 'int_field');
    if ($int_field !== null) {
      $obj->int_field = await \MyTypeIntWrapper::genFromThrift<\thrift_adapted_types\i64WithWrapper>(HH\FIXME\UNSAFE_CAST<mixed, \thrift_adapted_types\i64WithWrapper>($int_field, 'Map value is mixed'));
    }
    return $obj;
  }

  public function getName()[]: string {
    return 'structured_annotation_recursive';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "annotations.structured_annotation_recursive",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "name",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_struct" => tmeta_ThriftStructType::fromShape(
                    shape(
                      "name" => "annotations.structured_annotation_recursive",
                    )
                  ),
                )
              ),
              "name" => "recurse",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 3,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_struct" => tmeta_ThriftStructType::fromShape(
                    shape(
                      "name" => "annotations.structured_annotation_with_default",
                    )
                  ),
                )
              ),
              "name" => "default",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 4,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_map" => tmeta_ThriftMapType::fromShape(
                    shape(
                      "keyType" => tmeta_ThriftType::fromShape(
                        shape(
                          "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                        )
                      ),
                      "valueType" => tmeta_ThriftType::fromShape(
                        shape(
                          "t_struct" => tmeta_ThriftStructType::fromShape(
                            shape(
                              "name" => "annotations.structured_annotation_recursive",
                            )
                          ),
                        )
                      ),
                    )
                  ),
                )
              ),
              "name" => "recurse_map",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 5,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_typedef" => tmeta_ThriftTypedefType::fromShape(
                    shape(
                      "name" => "annotations.i64WithWrapper",
                      "underlyingType" => tmeta_ThriftType::fromShape(
                        shape(
                          "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                        )
                      ),
                    )
                  ),
                )
              ),
              "name" => "int_field",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'recurse' => shape(
          'field' => dict[
            '\facebook\thrift\annotation\hack\FieldWrapper' => \facebook\thrift\annotation\hack\FieldWrapper::fromShape(
              shape(
                "name" => "MyFieldWrapper",
              )
            ),
          ],
          'type' => dict[],
        ),
        'int_field' => shape(
          'field' => dict[],
          'type' => dict[
            '\facebook\thrift\annotation\hack\Wrapper' => \facebook\thrift\annotation\hack\Wrapper::fromShape(
              shape(
                "name" => "\\MyTypeIntWrapper",
              )
            ),
          ],
        ),
      ],
    );
  }

  public static function __stringifyMapKeys<T>(dict<arraykey, T> $m)[]: dict<string, T> {
    return Dict\map_keys($m, $key ==> (string)$key);
  }

  public static async function __genFromShape(self::TShape $shape): Awaitable<this> {
    $obj = new static();
    $obj->name = $shape['name'];
    $recurse = Shapes::idx($shape, 'recurse');
    if ($recurse !== null) {
      $recurse = await structured_annotation_recursive::__genFromShape($recurse);
      await $obj->get_recurse()->genWrap($recurse);
    }
    $default = Shapes::idx($shape, 'default');
    if ($default !== null) {
      $obj->default = structured_annotation_with_default::__fromShape($default);
    }
    $obj->recurse_map = self::__stringifyMapKeys(
      await Dict\map_async(
        $shape['recurse_map'],
        async $val0 ==> 
          await structured_annotation_recursive::__genFromShape($val0)
      )
    );
    $obj->int_field = await \MyTypeIntWrapper::genFromThrift<\thrift_adapted_types\i64WithWrapper>($shape['int_field']);
    return $obj;
  }

  public async function __genToShape(): Awaitable<self::TShape> {
    $recurse = await ($this->recurse as nonnull)->genUnwrap();
    $int_field = await $this->int_field->genUnwrap();
    return shape(
      'name' => $this->name,
      'recurse' => await ($recurse === null 
        ? null 
        : (
        $recurse->__genToShape()
        )
      ),
      'default' => ($this->default === null 
        ? null 
        : (
        $this->default->__toShape()
        )
      ),
      'recurse_map' => await Dict\map_async(
        $this->recurse_map,
        async $val0 ==> 
          await $val0->__genToShape()
      ),
      'int_field' => $int_field,
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'name') !== null) {
      $this->name = HH\FIXME\UNSAFE_CAST<mixed, string>($parsed['name']);
    }
    if (idx($parsed, 'recurse') !== null) {
      $_tmp0 = \json_encode(HH\FIXME\UNSAFE_CAST<mixed, structured_annotation_recursive>($parsed['recurse']));
      $_tmp1 = structured_annotation_recursive::withDefaultValues();
      $_tmp1->readFromJson($_tmp0);
      $this->recurse = $_tmp1;
    }
    if (idx($parsed, 'default') !== null) {
      $_tmp2 = \json_encode(HH\FIXME\UNSAFE_CAST<mixed, structured_annotation_with_default>($parsed['default']));
      $_tmp3 = structured_annotation_with_default::withDefaultValues();
      $_tmp3->readFromJson($_tmp2);
      $this->default = $_tmp3;
    }
    if (idx($parsed, 'recurse_map') !== null) {
      $_json7 = HH\FIXME\UNSAFE_CAST<mixed, dict<string, structured_annotation_recursive>>($parsed['recurse_map']);
      $_container8 = dict[];
      foreach($_json7 as $_key5 => $_value6) {
        $_value9 = structured_annotation_recursive::withDefaultValues();
        $_tmp10 = \json_encode($_value6);
        $_tmp11 = structured_annotation_recursive::withDefaultValues();
        $_tmp11->readFromJson($_tmp10);
        $_value9 = $_tmp11;
        $_container8[$_key5] = $_value9;
      }
      $this->recurse_map = $_container8;
    }
    if (idx($parsed, 'int_field') !== null) {
      $this->int_field = HH\FIXME\UNSAFE_CAST<mixed, i64WithWrapper>($parsed['int_field']);
    }
  }

}

/**
 * Original thrift struct:-
 * MyStruct
 */
class MyStruct implements \IThriftSyncStruct, \IThriftStructMetadata, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
    1 => shape(
      'var' => 'annotated_recursive',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'annotated_struct_wrapper',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'annotated_recursive' => 1,
    'annotated_struct_wrapper' => 2,
  ];

  const type TConstructorShape = shape(
    ?'annotated_recursive' => ?string,
    ?'annotated_struct_wrapper' => ?string,
  );

  const type TShape = shape(
    'annotated_recursive' => string,
    'annotated_struct_wrapper' => string,
  );
  const int STRUCTURAL_ID = 589959247947768145;
  /**
   * Original thrift field:-
   * 1: string annotated_recursive
   */
  public string $annotated_recursive;
  /**
   * Original thrift field:-
   * 2: string annotated_struct_wrapper
   */
  public string $annotated_struct_wrapper;

  public function __construct(?string $annotated_recursive = null, ?string $annotated_struct_wrapper = null)[] {
    $this->annotated_recursive = $annotated_recursive ?? '';
    $this->annotated_struct_wrapper = $annotated_struct_wrapper ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'annotated_recursive'),
      Shapes::idx($shape, 'annotated_struct_wrapper'),
    );
  }

  public static function fromMap_DEPRECATED(@KeyedContainer<string, mixed> $map)[]: this {
    return new static(
      HH\FIXME\UNSAFE_CAST<mixed, string>(idx($map, 'annotated_recursive'), 'map value is mixed'),
      HH\FIXME\UNSAFE_CAST<mixed, string>(idx($map, 'annotated_struct_wrapper'), 'map value is mixed'),
    );
  }

  public function getName()[]: string {
    return 'MyStruct';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "annotations.MyStruct",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "annotated_recursive",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "annotated_struct_wrapper",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    $structured_annotation_recursive0 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive0->name = "abc_struct";

    $structured_annotation_recursive1 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive1->name = "cba_struct";

    $structured_annotation_recursive0->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive1);

    $structured_annotation_recursive0->default = structured_annotation_with_default::fromShape(
      shape(
        "count" => 3,
      )
    );

    $structured_annotation_recursive2 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive2->name = "key_struct1";

    $structured_annotation_recursive3 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive3->name = "def_struct";

    $structured_annotation_recursive2->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive3);

    $structured_annotation_recursive4 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive4->name = "key_struct2";

    $structured_annotation_recursive5 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive5->name = "fed_struct";

    $structured_annotation_recursive4->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive5);

    $structured_annotation_recursive0->recurse_map = dict[
      "key_struct1" => $structured_annotation_recursive2,
      "key_struct2" => $structured_annotation_recursive4,
    ];

    $structured_annotation_recursive0->int_field = \MyTypeIntWrapper::fromThrift_DO_NOT_USE_THRIFT_INTERNAL<\thrift_adapted_types\i64WithWrapper>(10);

    $structured_annotation_recursive6 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive6->name = "abc_struct_field";

    $structured_annotation_recursive7 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive7->name = "cba_struct_field";

    $structured_annotation_recursive6->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive7);

    $structured_annotation_recursive6->default = structured_annotation_with_default::fromShape(
      shape(
        "count" => 3,
      )
    );

    $structured_annotation_recursive8 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive8->name = "key_struct_field1";

    $structured_annotation_recursive9 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive9->name = "def_struct_field";

    $structured_annotation_recursive8->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive9);

    $structured_annotation_recursive10 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive10->name = "key_struct_field2";

    $structured_annotation_recursive11 = structured_annotation_recursive::withDefaultValues();
    $structured_annotation_recursive11->name = "fed_struct_field";

    $structured_annotation_recursive10->get_recurse()->setValue_DO_NOT_USE_THRIFT_INTERNAL($structured_annotation_recursive11);

    $structured_annotation_recursive6->recurse_map = dict[
      "key_struct_field1" => $structured_annotation_recursive8,
      "key_struct_field2" => $structured_annotation_recursive10,
    ];

    return shape(
      'struct' => dict[
        'structured_annotation_recursive' => $structured_annotation_recursive0,
      ],
      'fields' => dict[
        'annotated_recursive' => shape(
          'field' => dict[
            'structured_annotation_recursive' => $structured_annotation_recursive6,
          ],
          'type' => dict[],
        ),
        'annotated_struct_wrapper' => shape(
          'field' => dict[
            'StructWithWrapper' => \thrift_adapted_types\StructWithWrapper::fromShape(
              shape(
                "int_field" => 11,
              )
            ),
          ],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function __stringifyMapKeys<T>(dict<arraykey, T> $m)[]: dict<string, T> {
    return Dict\map_keys($m, $key ==> (string)$key);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
      $shape['annotated_recursive'],
      $shape['annotated_struct_wrapper'],
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
      'annotated_recursive' => $this->annotated_recursive,
      'annotated_struct_wrapper' => $this->annotated_struct_wrapper,
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'annotated_recursive') !== null) {
      $this->annotated_recursive = HH\FIXME\UNSAFE_CAST<mixed, string>($parsed['annotated_recursive']);
    }
    if (idx($parsed, 'annotated_struct_wrapper') !== null) {
      $this->annotated_struct_wrapper = HH\FIXME\UNSAFE_CAST<mixed, string>($parsed['annotated_struct_wrapper']);
    }
  }

}

