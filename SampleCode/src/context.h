#ifndef MYAPI_CONTEXT_H
#define MYAPI_CONTEXT_H
#include <sgContext.h>
#include <api2UserCommands.h>
namespace API2
{

/**
 * @brief The FrontEndParameters struct
 */
struct FrontEndParameters
{
    SIGNED_LONG _symbolIdFirstLeg;
    SIGNED_LONG _symbolIdSecondLeg;
    SIGNED_LONG _totalQty;
    API2::DATA_TYPES::OrderMode _firstLegOrderMode;
    SIGNED_LONG _minProfit;
    SIGNED_LONG _orderQty;
    FrontEndParameters():
        _symbolIdFirstLeg(0),
        _symbolIdSecondLeg(0),
        _totalQty(125),
        _firstLegOrderMode(API2::CONSTANTS::CMD_OrderMode_BUY),
        _minProfit(0),
        _orderQty(125)
    {
    }
};

/**
 * @brief The StrategySavedQty struct
 */
struct StrategySavedQty
{
    /**
     * @brief _firstLegTradedQty
     */
    SIGNED_LONG _firstLegTradedQty;

    /**
     * @brief StrategySavedQty
     */
    StrategySavedQty():
        _firstLegTradedQty(0)
    {
    }
};

/**
 * @brief The Context class
 */
class Context: public API2::SGContext
{
    /**
     * @brief _currentOrderId
     */
    API2::COMMON::OrderId *_currentOrderId;

    /**
     * @brief _params
     */
    FrontEndParameters _params;

    /**
     * @brief _savedQty
     */
    StrategySavedQty _savedQty;

    /**
     * @brief _firstLegInstrument
     */
    API2::COMMON::Instrument *_firstLegInstrument;

    /**
     * @brief _secondLegInstrument
     */
    API2::COMMON::Instrument *_secondLegInstrument;

    /**
     *
     */
    void (*_state)(Context &obj);

    /**
     * @brief _firstLegOrder
     */
    API2::SingleOrder *_firstLegOrder;

    /**
     * @brief _firstLegOrderId
     */
    API2::COMMON::OrderId *_firstLegOrderId;

    /**
     * @brief _secondLegOrder
     */
    API2::SingleOrder *_secondLegOrder;

    /**
     * @brief _secondLegOrderId
     */
    API2::COMMON::OrderId *_secondLegOrderId;

    /**
     * @brief _replaceOrder
     */
    API2::SingleOrder *_replaceOrder;
public:

    /**
     * @brief Context
     * @param params
     */
    Context(API2::StrategyParameters *params);

    /**
     * @brief processCurrentState
     */
    void OnDefaultEvent();

    /**
     * @brief OnCMDModifyStrategy
     */
    void onCMDModifyStrategy(API2::AbstractUserParams*);

    /**
     * @brief setInternalParameters
     * @param futfutParams
     * @param params
     */
    void setInternalParameters(API2::UserParams *futfutParams,
                               API2::FrontEndParameters &params);

    /**
     * @brief registerSymbols
     */
    void registerSymbols();

    /**
     * @brief createOrderIds
     */
    void createOrderIds();

    /**
     * @brief OnMarketDataEvent
     * @param symbolId
     */
    void OnMarketDataEvent(UNSIGNED_LONG symbolId);

    /**
     * @brief getFirstLegPrice
     * @return
     */
    SIGNED_LONG getFirstLegPrice();

    /**
     * @brief cancelOrder
     */
    void cancelOrder();

    /**
     * @brief onProcessOrderConfirmattion
     * @param confirmation
     */
    void onProcessOrderConfirmation(API2::OrderConfirmation &confirmation);

    /**
     * @brief onNewConfirmed
     * @param confirmation
     * @param orderId
     */
    void onNewConfirmed(API2::OrderConfirmation &confirmation,
                        API2::COMMON::OrderId *orderId);

    /**
     * @brief onReplaced
     * @param confirmation
     * @param orderId
     */
    void onReplaced(API2::OrderConfirmation &confirmation,API2::COMMON::OrderId *orderId);

    /**
     * @brief onCanceled
     * @param confirmation
     * @param orderId
     */
    void onCanceled(API2::OrderConfirmation &confirmation,
                    API2::COMMON::OrderId *orderId);

    /**
     * @brief placeFirstLegOrder
     * @param obj
     */
    static void placeFirstLegOrder(Context &obj);

    /**
     * @brief waitState
     * @param obj
     */
    static void waitState(Context &obj);

    /**
     * @brief replaceOrder
     * @param obj
     */
    static void replaceOrder(Context &obj);

};

/**
 * @brief Strategy Driver
 * @param obj
 */
void *FutFutDriver(void *params);
}
#endif
